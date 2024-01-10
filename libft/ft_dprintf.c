/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:00:36 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 19:07:38 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	ap;
	int		i;
	int		nbc;

	if (!str)
		return (-1);
	va_start(ap, str);
	i = 0;
	nbc = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			nbc = nbc + print_type(str[i + 1], ap);
			i++;
		}
		else
		{
			write(fd, &str[i], 1);
			nbc++;
		}
		i++;
	}
	return (nbc);
}
