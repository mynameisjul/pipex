/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:43:13 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/09 10:49:14 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	size_t	i;
	size_t	j;
	size_t	s_little;

	b = (char *) big;
	i = 0;
	j = 0;
	s_little = ft_strlen(little);
	if (s_little == 0)
		return (b);
	while (b[i] != 0 && len > i)
	{
		if (b[i + j] == little[j])
		{
			while (b[i + j] == little[j] && len - (i + j) > 0 && little[j] != 0)
				j++;
			if (j == s_little)
				return (&b[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
