/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:55 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 17:27:56 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **paths_tab(char **ev)
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
	path = (char *) ft_calloc(j, sizeof(char));
	if (!path)
		return (NULL);
	j = 0;
	while (ev[i][j + 5] != 0)
	{
		path[j] = ev[i][j + 5];
		j++;
	}
	paths = ft_split(path, ":");
	return (free(path), paths);
}

int	path_index(char *cmd, char **ev)
{
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	paths = paths_tab(ev);
	while (paths[i] != 0)
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (-1);
		if(access(cmd_path, F_OK | X_OK) == 0)
			return (i);
		free(cmd_path);		
	}
	return (-1);
}
