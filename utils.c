/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:55 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/19 12:57:13 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*file_name_generator(char *file_name)
{
	int		i;

	i = 1;
	file_name = (char *) ft_calloc(2, sizeof(char));
	file_name = ft_memset(file_name, 'a', i);
	while (file_name && access(file_name, F_OK) == 0 && ++i)
	{
		free(file_name);
		file_name = (char *) ft_calloc(i + 1, sizeof(char));
		ft_memset(file_name, 'a', i);
	}
	return (file_name);
}

/* ./pipex here_doc LIMITER cmd cmd1 file */

int	here_doc_file(char *limiter)
{
	int		*fd_heredoc;
	char	*file_name;
	char	*line;

	(file_name = NULL, file_name = file_name_generator(file_name));
	if (!file_name)
		return (-1);
	fd_heredoc = (int []){-1, -1};
	fd_heredoc[0] = open(file_name, O_RDONLY| O_CREAT, 0644);
	if (fd_heredoc[0] == -1)
		return (ft_dprintf(2, "failed to open here_doc\n"), -1);
	fd_heredoc[1] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_heredoc[1] == -1)
	{
		(close(fd_heredoc[0]), unlink(file_name), free(file_name));
		return (ft_dprintf(2, "failed to open here_doc\n"), -1);
	}
	while (ft_dprintf(1, "heredoc> ") && oget_next_line(0, &line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
			ft_dprintf(fd_heredoc[1], line);
		else
			break;
	}
	return (close(fd_heredoc[1]), unlink(file_name), free(file_name), fd_heredoc[0]);
}

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
		return (ft_dprintf(2, "Command '' not found\n"),ft_freesplit(paths), NULL);
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
	ft_dprintf(2, "Command '%s' not found\n", cmd);
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
		return (close(*in), perror("outfile"));
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
