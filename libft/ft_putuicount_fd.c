/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuicount_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:58:07 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 18:43:01 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuicount_fd(int *count, unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putuicount_fd(count, n / 10, fd);
		ft_putcharcount_fd(count, n % 10 + '0', fd);
	}
	else
		ft_putcharcount_fd(count, n % 10 + '0', fd);
}
