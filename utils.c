/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julieblaye <julieblaye@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:55 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/11 12:43:55 by julieblaye       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Paths tab recupere dans les parametres d'env celui commencant par PATH 
et separe dans un tableau de str tous les paths possibles avec le separateur : 
Renvoie le tableau de str et free la str temporaire */

char **pathstab(char **ev)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;

	i = 0;
	while (ft_strncmp("PATH=", ev[i], 5) != 0)
		i++;
	j = 0;
	while (ev[i][j + 5] != ':' && ev[i][j + 5] != 0)
		j++;
	path = (char *) ft_calloc(j + 1, sizeof(char));
	if (!path)
		return (NULL);
	j = 0;
	while (ev[i][j + 5] != 0)
	{
		path[j] = ev[i][j + 5];
		j++;
	}
	paths = ft_split(path, ':');
	return (free(path), paths);
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
		return (NULL);
	while (paths[i] != 0)
	{
		cmd_path = ft_strjoin(paths[i], cmd_name);
		if (!cmd_path)
			return (free(cmd_name), ft_freesplit(paths), NULL);
		if(access(cmd_path, F_OK | X_OK) == 0)
			return (ft_freesplit(paths), free(cmd_name), cmd_path);
	}
	return (free(cmd_name), ft_freesplit(paths), NULL);
}
