/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:16:01 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/17 15:26:13 by jblaye           ###   ########.fr       */
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
# include <errno.h>
# include "libft/libft.h"

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
char	*file_name_generator(char *file_name);
int		here_doc_file(char *limiter);
char	*cmdpath(char *cmd, char **paths);
char	*find_path(char *cmd, char **ev);
void	close_fd(int fds[4], int fdio[2]);

//PIPEX FUNCTIONS
void	process_fdio(int *in, int *out, int ac, char **av);
int		exec_child(char *full_cmd, int fds[4], int fdio[2], char **ev);
void	exec_multipipe(int ac, char **av, char **ev, int fdio[2]);
int		wait_process(int pid);

#endif