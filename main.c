/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 13:08:23 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	int		fd[2];
	//int		i;
	__pid_t	pid;
	char	**execav;
	char	*path;

	//i = 2;
	//while (i < ac - 2)
	//{
		pipe(fd);
		pid = fork();
		
		if (pid == -1)
			return (perror("fork"), 1);
		if (pid == 0)
		{
			dup2(0, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			(close(fd[0]), close(fd[1]));
			execav = ft_split(av[1], ' ');
			path = pathname(ev);
			dprintf(2, ".%s\n", path);
			if (execve("/usr/bin/cat", execav, ev) < 0)
				return (perror("execve"), 1);
		}
		close(fd[0]);
		pid = fork();
		
		if (pid == -1)
			return (perror("fork"), 1);
		if (pid == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(1, STDOUT_FILENO);
			(close(fd[0]), close(fd[1]));
			execav = ft_split(av[2], ' ');
			path = pathname(ev);
			if (execve("/usr/bin/cat", execav, ev) < 0)
				return (perror("execve"), 1);
		}
		close(fd[1]);
		
		//i++;
		
	// on cree le pipe
	// puis on forke
	// on redirige le fd[0] du child vers stdin
	// on close les fds
	// on execute la commande du child
	// on sort
	// on close la partie read fd[0]
	// on ecrit dans fd[1] l'output du parent
	// on ferme fd[1]
	// on wait sur les childs
	// gestion des erreurs
}
