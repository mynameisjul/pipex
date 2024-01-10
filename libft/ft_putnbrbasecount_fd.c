/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbasecount_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:06:41 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 17:46:58 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbasecount_fd(int *count, unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putnbrbasecount_fd(count, nbr / 16, fd);
		ft_putcharcount_fd(count, base[nbr % 16], fd);
	}
	else
	{
		ft_putcharcount_fd(count, base[nbr], fd);
	}
}
