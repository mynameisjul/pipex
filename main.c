/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/15 11:46:14 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_child(char *full_cmd, int fds[4], char **ev)
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
		dup2(fds[3], STDOUT_FILENO);
		(close(fds[0]), close(fds[1]), close(fds[2]), close(fds[3]));
		execav = ft_split(full_cmd, ' ');
		if (!execav)
			return (ft_dprintf(2, "Memory error"), -1);
		path = cmdpath(execav[0], ev);
		if (execve(path, execav, ev) < 0)
			return (perror("execve"), -1);
	}
	return (pid);
}

void	exec_multipipe(int ac, char **av, char **ev, int fdio[2])
{
	int	*fds;
	int	fdpipe[2];
	int	i;
	int pid;
	int	status;

	i = 2;
	if (pipe(fdpipe) == -1)
		return (perror("pipe"));
	fds = (int []) {fdio[0], -1, fdpipe[0], fdpipe[1]};
	while (i < ac - 1)
	{
		pid = exec_child(av[i], fds, ev);
		if (i == ac - 3)
			fds = (int []) { fdpipe[0], fdpipe[1], -1, fdio[1]};
		else
		{
			if (pipe(fdpipe) == - 1)
				return (perror("pipes"));
			fds = (int []) {fds[2], fds[3], fdpipe[0], fdpipe[1]};
		}
		i++;
	}
	wait(&status);
}

int	main(int ac, char **av, char **ev)
{
	int	fdio[2];

	process_fdio(&fdio[0], &fdio[1], ac, av);
	if (ac < 5 || fdio[0] == -1 || fdio[1] == -1)
		return (ft_dprintf(2, "Invalid arguments"));
	exec_multipipe(ac, av, ev, fdio);
	return (0);
}
