/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:55 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/16 14:31:17 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Paths tab recupere dans les parametres d'env celui commencant par PATH 
et separe dans un tableau de str tous les paths possibles avec le separateur : 
Renvoie le tableau de str*/

char	**pathstab(char **ev)
{
	int		i;
	char	**paths;

	i = 0;
	if (!ev || !ev[0])
		return (NULL);
	while (ev[i] && ft_strncmp("PATH=", ev[i], 5) != 0)
		i++;
	paths = ft_split(ev[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

/* cmdpath parcours le tableau de chemins potentiels pour la commande cmd
et renvoie la str qui correspond au bon chemin, null sinon */

char	*cmdpath(char *cmd, char **ev)
{
	int		i;
	char	**paths;
	char	*cmd_name;
	char	*cmd_path;

	i = 0;
	paths = pathstab(ev);
	if (!paths)
		return (NULL);
	cmd_name = ft_strjoin("/", cmd);
	if (!cmd_name)
		return (ft_freesplit(paths), NULL);
	while (paths[i] != 0)
	{
		cmd_path = ft_strjoin(paths[i], cmd_name);
		if (!cmd_path)
			return (free(cmd_name), ft_freesplit(paths), NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (ft_freesplit(paths), free(cmd_name), cmd_path);
		free(cmd_path);
		i++;
	}
	return (free(cmd_name), ft_freesplit(paths), NULL);
}

/* On ouvre le infile et outfile s ils existent */

void	process_fdio(int *in, int *out, int ac, char **av)
{
	*in = open(av[1], O_RDONLY, 0644);
	if (*in == -1)
		return (perror("infile"));
	if (ft_strncmp("here_doc", av[1], 8) == 0)
	{
		*out = -1;
		return ;
	}
	*out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*out == -1)
		return (perror("outfile"));
}

void	close_fd(int fds[4], int fdio[2])
{
	int	i;

	i = 0;
	if (fdio && fdio[0] != -1 && fdio[0] != fds[0])
		close(fdio[0]);
	if (fdio && fdio[1] != -1 && fdio[1] != fds[3])
		close(fdio[1]);
	while (fds && i < 4)
	{
		if (fds[i] != -1)
			close (fds[i]);
		i++;
	}
}
