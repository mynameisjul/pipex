/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:26 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/07 14:54:05 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	lensrc;

	lensrc = ft_strlen(src);
	if (size > 0)
	{
		while (*src != 0 && size - 1 > 0)
		{
			*dst = *src;
			src++;
			dst++;
			size--;
		}
		*dst = 0;
	}
	return (lensrc);
}
