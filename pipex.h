/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:16:01 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/12 17:03:54 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <aio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_childfd 
{
	int	fds[2];
	int	fdio[2];
	int	pos;	// if pos = 0 use infile =, if pos = 1 use outfile, else use pipes fds
}				t_childfd;

//ALLOC FUNCTIONS
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

//CHAR FUNCTIONS
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_freesplit(char **tab);

//UTILS FUNCTIONS
char	**pathstab(char **ev);
char	*cmdpath(char *cmd, char **paths);

//PIPEX FUNCTIONS
void	process_fdio(int *in, int *out, int ac, char **av);
void	exec_child(char *full_cmd, int read, int write, char **ev);
void	exec_multipipe(int ac, char **av, char **ev);


#endif