/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcount_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:53:50 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 17:47:01 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrcount_fd(int *count, int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*count = 11;
		return ;
	}
	if (n < 0)
	{
		n = -n ;
		*count = *count + 1;
		write (fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbrcount_fd(count, n / 10, fd);
		ft_putcharcount_fd(count, n % 10 + '0', fd);
	}
	else
		ft_putcharcount_fd(count, n % 10 + '0', fd);
}
