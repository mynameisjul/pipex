/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:50 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/12 09:44:56 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wordlen(char const *s, char c)
{
	size_t	wlen;

	wlen = 0;
	while (*s != c && *s != 0)
	{
		s++;
		wlen++;
	}
	return (wlen);
}

size_t	wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s != 0)
			count++;
		while (*s != c && *s != 0)
			s++;
	}
	return (count);
}

char	*partialstrdup(char const *s, char c)
{
	size_t	wlen;
	size_t	i;
	char	*r;

	wlen = wordlen(s, c);
	i = 0;
	r = (char *) malloc(sizeof(char) * (wlen + 1));
	if (!r)
		return (0);
	while (i < wlen)
	{
		r[i] = *s;
		s++;
		i++;
	}
	r[i] = 0;
	return (r);
}

char	**mallocprotec(char **r, int len)
{
	int	i;
	int	success;

	i = 0;
	success = 1;
	while (i < len)
	{
		if (!r[i])
			success = 0;
		i++;
	}
	if (success == 0)
	{
		i = 0;
		while (i <= len)
		{
			if (r[i])
				free(r[i]);
			i++;
		}
		free(r);
		return (0);
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	r = (char **) ft_calloc(wordcount(s, c) + 1, sizeof(char *));
	if (!r)
		return (0);
	while (*s != 0)
	{
		while (*s != 0 && *s == c)
			s++;
		if (*s != 0)
		{
			r[i] = partialstrdup(s, c);
			i++;
		}
		while (*s != c && *s != 0)
			s++;
	}
	r[i] = NULL;
	r = mallocprotec(r, i);
	return (r);
}
