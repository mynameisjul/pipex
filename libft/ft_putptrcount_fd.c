/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrcount_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:24:16 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 18:40:33 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptrrecurs(int *count, unsigned long int nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putptrrecurs(count, nbr / 16, fd);
		ft_putcharcount_fd(count, base[nbr % 16], fd);
	}
	else
		ft_putcharcount_fd(count, base[nbr], fd);
}

void	ft_putptrcount_fd(int *count, unsigned long int nbr, int fd)
{
	if (!nbr)
		ft_putstrcount_fd(count, "(nil)", fd);
	else
	{
		ft_putstrcount_fd(count, "0x", fd);
		ft_putptrrecurs(count, nbr, fd);
	}
}
