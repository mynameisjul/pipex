/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:54:12 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/17 13:55:50 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*us;
	char	uc;
	int		i;

	us = (char *) s;
	if (!us)
		return (NULL);
	uc = (char) c;
	i = 0;
	while (n > 0)
	{
		us[i] = uc;
		i++;
		n--;
	}
	return (us);
}
