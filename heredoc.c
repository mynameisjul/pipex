/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:31:44 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/23 10:39:21 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	isheredoc(char **av)
{
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		return (1);
	return (0);
}

char	*file_name_generator(char *file_name)
{
	int		i;

	i = 1;
	file_name = (char *) ft_calloc(2, sizeof(char));
	file_name = ft_memset(file_name, 'a', i);
	while (file_name && access(file_name, F_OK) == 0 && ++i)
	{
		free(file_name);
		file_name = (char *) ft_calloc(i + 1, sizeof(char));
		ft_memset(file_name, 'a', i);
	}
	return (file_name);
}

static void	norminette_file_name(char **name)
{
	*name = NULL;
	*name = file_name_generator(*name);
}

char	*limiter_generator(char *limiter)
{
	char	*f_l;
	char	len;
	int		i;

	len = 0;
	i = 0;
	if (limiter)
		len = ft_strlen(limiter);
	f_l = (char *) ft_calloc(len + 2, sizeof(char));
	if (!f_l)
		return (NULL);
	while (i < len)
	{
		f_l[i] = limiter[i];
		i++;
	}
	f_l[i] = '\n';
	return (f_l);
}

/* ./pipex here_doc LIMITER cmd cmd1 file */

int	here_doc_file(char *limiter)
{
	int		*fd_hd;
	char	*fname;
	char	*line;

	norminette_file_name(&fname);
	if (!fname)
		return (-1);
	fd_hd = (int []){-1, -1};
	fd_hd[0] = open(fname, O_RDONLY | O_CREAT, 0644);
	if (fd_hd[0] == -1)
		return (ft_dprintf(2, "failed to open here_doc\n"), -1);
	fd_hd[1] = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_hd[1] == -1)
	{
		(close(fd_hd[0]), unlink(fname), free(fname));
		return (ft_dprintf(2, "failed to open here_doc\n"), -1);
	}
	while (ft_dprintf(1, "heredoc> ") && oget_next_line(0, &line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) != 0)
			(ft_dprintf(fd_hd[1], line), free(line));
		else
			break ;
	}
	return (free(line), close(fd_hd[1]), unlink(fname), free(fname), fd_hd[0]);
}
