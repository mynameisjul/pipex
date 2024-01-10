/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrupbasecount_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:06:41 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 17:47:05 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrupbasecount_fd(int *count, unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putnbrupbasecount_fd(count, nbr / 16, fd);
		ft_putcharcount_fd(count, base[nbr % 16], fd);
	}
	else
	{
		ft_putcharcount_fd(count, base[nbr], fd);
	}
}
