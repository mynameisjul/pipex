/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:19:05 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/17 14:47:39 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*oget_next_line(int fd, char **line)
{
	*line = get_next_line(fd);
	return (*line);
}

char	*ft_strnjoin(char *beg, char *end, size_t size)
{
	char	*r;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (beg && beg[len] != 0)
		len++;
	r = (char *) ft_calloc(len + size + 1, sizeof(char));
	if (!r)
		return (0);
	while (beg && beg[i] != 0)
	{
		r[i] = beg[i];
		i++;
	}
	while (end[i - len] != 0 && i - len < size)
	{
		r[i] = end[i - len];
		i++;
	}
	if (beg)
		free(beg);
	return (r);
}

t_line	ft_read(int fd, t_line line)
{
	ssize_t	i;

	i = 0;
	while (read(fd, line.rest, BUFFER_SIZE) > 0)
	{
		i = isinstr(line.rest, '\n');
		line.result = ft_strnjoin(line.result, line.rest, i + 1);
		line.rest = ft_endstr(line.rest, i + 1, BUFFER_SIZE);
		if (!line.rest || !line.result)
		{
			if (line.result)
				free(line.result);
			line.result = NULL;
			return (line);
		}
		if (i < BUFFER_SIZE)
			return (line);
	}
	if (read(fd, line.rest, BUFFER_SIZE) <= 0 && line.result[0] == 0)
	{
		free(line.result);
		line.result = NULL;
		return (line);
	}
	return (line);
}

t_line	get_end_of_line(int fd, char *tmp)
{
	t_line	line;
	ssize_t	i;

	line.result = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line.rest = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 0;
	if (tmp[0] != 0)
	{
		i = isinstr(tmp, '\n');
		line.result = ft_strnjoin(line.result, tmp, i + 1);
		if (!line.rest || !line.result)
		{
			if (line.result)
				free(line.result);
			line.result = NULL;
			return (line);
		}
		free(line.rest);
		line.rest = ft_endstrnomalloc(tmp, i + 1, BUFFER_SIZE);
		if (isinstr(line.result, '\n') < BUFFER_SIZE)
			return (line);
	}
	line = ft_read(fd, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	tmp[BUFFER_SIZE + 1] = {0};
	t_line		line;
	ssize_t		i;	

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_end_of_line(fd, tmp);
	i = 0;
	if (line.rest)
	{
		while (line.rest[i] != 0)
		{
			tmp[i] = line.rest[i];
			i++;
		}
		free(line.rest);
	}
	if (!line.result)
		return (NULL);
	while (i < BUFFER_SIZE)
	{
		tmp[i] = 0;
		i++;
	}
	return (line.result);
}
