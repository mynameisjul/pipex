/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:14 by jblaye            #+#    #+#             */
/*   Updated: 2023/12/21 15:44:36 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *pathname(char **ev)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH=", ev[i], 5) != 0)
		i++;
	j = 0;
	while (ev[i][j + 5] != ':' && ev[i][j + 5] != 0)
		j++;
	path = (char *) ft_calloc(j, sizeof(char));
	if (!path)
		return (NULL);
	j = 0;
	while (ev[i][j + 5] != ':' && ev[i][j + 5] != 0)
	{
		path[j] = ev[i][j + 5];
		j++;
	}
	return (path);
}

int	main(int ac, char **av, char **ev)
{
	int		fd[2];
	int		i;
	__pid_t	pid;
	char	**execav;
	char	*path;

	i = 2;
	while (i < ac - 2)
	{
		pipe(fd);
		pid = fork();
		
		if (pid == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			close(fd[1]);
			execav = ft_split(av[i], ' ');
			path = pathname(ev);
			if (execve(path, execav, ev) < 0)
				exit (0);
		}
	
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
