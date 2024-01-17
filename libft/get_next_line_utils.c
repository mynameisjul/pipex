/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:26:26 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/17 14:33:57 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	isinstr(char *s, char c)
{
	ssize_t	i;

	i = 0;
	if (s)
	{
		while (i < BUFFER_SIZE)
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (i);
}

char	*ft_endstr(char *rest, size_t index, size_t size)
{
	char	*r;
	size_t	i;

	r = (char *) ft_calloc(size + 1, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	if (rest)
	{
		while (i + index < size)
		{
			r[i] = rest[index + i];
			i++;
		}
		free(rest);
	}
	return (r);
}

char	*ft_endstrnomalloc(char *rest, size_t index, size_t size)
{
	char	*r;
	size_t	i;

	r = (char *) ft_calloc(size + 1, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	if (rest)
	{
		while (i + index < size)
		{
			r[i] = rest[index + i];
			i++;
		}
	}
	return (r);
}
