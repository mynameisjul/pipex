/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:47:20 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/10 16:36:11 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;
	int				i;

	udest = (unsigned char *) dest;
	usrc = (unsigned char *) src;
	i = 0;
	while (n > 0)
	{
		udest[i] = usrc[i];
		n--;
		i++;
	}
	return (dest);
}
