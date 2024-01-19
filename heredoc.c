/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:31:44 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/19 15:32:27 by jblaye           ###   ########.fr       */
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

/* ./pipex here_doc LIMITER cmd cmd1 file */

int	here_doc_file(char *limiter)
{
	int		*fd_hd;
	char	*file_name;
	char	*line;

	norminette_file_name(&file_name);
	if (!file_name)
		return (-1);
	fd_hd = (int []){-1, -1};
	fd_hd[0] = open(file_name, O_RDONLY | O_CREAT, 0644);
	if (fd_hd[0] == -1)
		return (ft_dprintf(2, "failed to open here_doc\n"), -1);
	fd_hd[1] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_hd[1] == -1)
	{
		(close(fd_hd[0]), unlink(file_name), free(file_name));
		return (ft_dprintf(2, "failed to open here_doc\n"), -1);
	}
	while (ft_dprintf(1, "heredoc> ") && oget_next_line(0, &line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
			ft_dprintf(fd_hd[1], line);
		else
			break ;
	}
	return (close(fd_hd[1]), unlink(file_name), free(file_name), fd_hd[0]);
}
