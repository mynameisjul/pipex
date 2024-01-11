/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julieblaye <julieblaye@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/11 22:09:17 by julieblaye       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char *cmd, 

int	main(int ac, char **av, char **ev)
{
	(void)	ac;
	int		status;
	int		fd[2];
	pid_t	pid;
	char	**execav;
	char	*path;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		(close(fd[0]), close(fd[1]));
		execav = ft_split(av[1], ' ');
		path = cmdpath(av[1], ev);
		dprintf(2, ".%s\n", path);
		if (execve(path, execav, ev) < 0)
			return (perror("execve"), 1);
	}
	(close(fd[0]), close(fd[1]));
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(1, STDOUT_FILENO);
		(close(fd[0]), close(fd[1]));
		execav = ft_split(av[2], ' ');
		path = cmdpath(av[2], ev);
		dprintf(2, ".%s\n", path);
		if (execve(path, execav, ev) < 0)
			return (perror("execve"), 1);
	}
	(close(fd[0]), close(fd[1]));
	waitpid(pid, &status, 0);
}
