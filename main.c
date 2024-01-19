/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/19 14:23:19 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* On ouvre le infile et outfile s ils existent */

void	process_fdio(int *in, int *out, int ac, char **av)
{
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		*in = here_doc_file(av[2]);
		if (*in == -1)
			return (perror("infile"));
		*out = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*out == -1)
			return (close(*in), perror("outfile"));
	}
	else
	{
		*in = open(av[1], O_RDONLY, 0644);
		if (*in == -1)
			return (perror("infile"));
		*out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*out == -1)
			return (close(*in), perror("outfile"));
	}
}

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
			return (perror("dup"), -1);
		close_fd(fds, fdio);
		execav = ft_split(full_cmd, ' ');
		if (!execav)
			return (ft_dprintf(2, "Memory error"), -1);
		path = cmdpath(execav[0], ev); // DEBUGGING MODIFIED 
		if (!path)
			(ft_freesplit(execav), exit(-1));
		if (path != 0 && execve(path, execav, ev) < 0)
			(perror("execve"), free(execav), free(path), exit(-1));
	}
	if (fds[1] != -1)
		close (fds[1]);
	return (close(fds[0]), close(fds[3]), pid);
}

void	exec_multipipe(int cmd_nbr, char **cmds, char **ev, int fdio[2])
{
	int	*fds;
	int	fdpipe[2];
	int	i;
	int	pid;

	i = 0;
	if (pipe(fdpipe) == -1)
		return (perror("pipe"));
	fds = (int []){fdio[0], -1, fdpipe[0], fdpipe[1]};
	while (i < cmd_nbr)
	{
		pid = exec_child(cmds[i], fds, fdio, ev);
		if (i == cmd_nbr - 1)
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
	int	cmd_nbr;

	cmd_nbr = 0;
	process_fdio(&fdio[0], &fdio[1], ac, av);
	if ((ft_strncmp("here_doc", av[1], 9) == 0 && ac < 6) || ac < 5)
		return (ft_dprintf(2, "Invalid arguments"));
	if (fdio[0] == -1 || fdio[1] == -1)
		return (ft_dprintf(2, "15\n"), -1);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		cmd_nbr = ac - 4;
		exec_multipipe(cmd_nbr, &av[3], ev, fdio);
	}
	else
	{
		cmd_nbr = ac - 3;
		exec_multipipe(cmd_nbr, &av[2], ev, fdio);
	}
	return (0);
}
