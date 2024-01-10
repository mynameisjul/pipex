/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:39:19 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/16 09:47:35 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set != 0)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	end;
	size_t	i;
	char	*r;

	end = 0;
	i = 0;
	if (!s1)
		return (0);
	while (*s1 != 0 && isset(*s1, set) == 1)
		s1++;
	if (!s1)
		return ((char *) ft_calloc (1, sizeof(char)));
	len = ft_strlen(s1);
	while (end < len && isset(s1[len - 1 - end], set) == 1)
		end++;
	r = (char *) ft_calloc ((len - end + 1), sizeof(char));
	if (!r)
		return (0);
	while (s1[i + end] != 0)
	{
		r[i] = s1[i];
		i++;
	}
	return (r);
}
