/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcount_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:47:26 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 18:42:38 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrcount_fd(int *count, char *str, int fd)
{
	if (!str)
		ft_putstrcount_fd(count, "(null)", fd);
	else
	{
		while (*str != 0)
		{
			ft_putcharcount_fd(count, *str, fd);
			str++;
		}
	}
}
