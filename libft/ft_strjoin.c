/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:22:46 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/17 13:10:37 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*r;

	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	r = (char *) malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!r)
		return (0);
	while (*s1 != 0)
	{
		*r = *s1;
		r++;
		s1++;
	}
	while (*s2 != 0)
	{
		*r = *s2;
		r++;
		s2++;
	}
	*r = '\0';
	return (r - lens1 - lens2);
}
