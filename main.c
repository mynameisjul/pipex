/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/12 15:53:13 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char *full_cmd, int fds[2], char **ev)
{
	char	**execav;
	char	*path;
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		dup2(fds[0], STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		(close(fds[0]), close(fds[1]));
		execav = ft_split(full_cmd, ' ');
		path = cmdpath(execav[0], ev);
		if (execve(path, execav, ev) < 0)
			return (perror("execve"), 1);
	}
}

void	exec_multipipe(int ac, char **av, char **ev)
{
	int	fds[2];
	int	i;

	i = 2;
	if (ac < 5)
		return ;
	pipe(fds);
	while (i < ac)
	{
		exec_child(av[i], fds, ev);
	}
	
}

int	main(int ac, char **av, char **ev)
{
	int		status;
	int		fd[2];
	int		fd_io[2];

	
	waitpid(pid, &status, 0);
}
