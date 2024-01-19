/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:48:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/19 15:22:22 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <aio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_line
{
	char	*result;
	char	*rest;
}					t_line;

//MALLOC FUNCTIONS
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_fsplit(char **tab);

//TYPECHAR FUNCTIONS
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

//TYPE CONVERT FUNCTIONS
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

//MEMORY FUNCTIONS
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

//STRING FUNCTIONS
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);

//PARCING FUNCTIONS
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//PRINTF FUNCTIONS
void	ft_putcharcount_fd(int *count, char c, int fd);
void	ft_putstrcount_fd(int *count, char *str, int fd);
void	ft_putnbrcount_fd(int *count, int n, int fd);
void	ft_putnbrbasecount_fd(int *count, unsigned int nbr, int fd);
void	ft_putnbrupbasecount_fd(int *count, unsigned int nbr, int fd);
void	ft_putuicount_fd(int *count, unsigned int n, int fd);
void	ft_putptrcount_fd(int *count, unsigned long int nbr, int fd);
int		print_type(char c, va_list ap);
int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);
void	ft_printinttab(int *tab, int len);
void	ft_printstrtab(char **tab);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//GET NEXT LINE UTILS
ssize_t	isinstr(char *s, char c);
char	*ft_endstr(char *rest, size_t index, size_t size);
char	*ft_endstrnomalloc(char *rest, size_t index, size_t size);

//GET NEXT LINE CORE FUNCTIONS
char	*ft_strnjoin(char *beg, char *end, size_t size);
t_line	ft_read(int fd, t_line line);
t_line	get_end_of_line(int fd, char *tmp);
char	*get_next_line(int fd);
char	*oget_next_line(int fd, char **line);

//CHAINED LISTS FUCTIONS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif