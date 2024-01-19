/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/19 14:50:14 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_child(char *full_cmd, int fds[4], int fdio[2], char **ev)
{
	char	**execav;
	char	*path;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), -1);
	if (pid == 0)
	{
		if (dup2(fds[0], 0) == -1 || dup2(fds[3], 1) == -1)
			perror("dup");
		close_fd(fds, fdio);
		execav = ft_split(full_cmd, ' ');
		if (!execav)
			return (ft_dprintf(2, "Memory error"), -1);
		path = path_name(execav[0], ev);
		if (!path)
			(ft_freesplit(execav), exit(-1));
		if (path != 0 && execve(path, execav, ev) < 0)
			(perror("execve"), free(execav), free(path), exit(-1));
	}
	if (fds[1] != -1)
		close (fds[1]);
	return (close(fds[0]), close(fds[3]), pid);
}

void	exec_multipipe(int ac, char **av, char **ev, int fdio[2])
{
	int	*fds;
	int	fdpipe[2];
	int	i;
	int	pid;

	i = 2;
	if (pipe(fdpipe) == -1)
		return (perror("pipe"));
	fds = (int []){fdio[0], -1, fdpipe[0], fdpipe[1]};
	while (i < ac - 1)
	{
		pid = exec_child(av[i], fds, fdio, ev);
		if (i == ac - 3)
			fds = (int []){fdpipe[0], fdpipe[1], -1, fdio[1]};
		else
		{
			if (pipe(fdpipe) == -1)
				return (perror("pipes"));
			fds = (int []){fds[2], fds[3], fdpipe[0], fdpipe[1]};
		}
		i++;
	}
	close_fd(fds, fdio);
	wait_process(pid);
}

int	wait_process(int pid)
{
	int	status;
	int	i;

	while (errno != ECHILD)
		if (wait(&status) == pid && WIFEXITED(status))
			i = WEXITSTATUS(status);
	if (pid == -1)
		return (127);
	return (i);
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
