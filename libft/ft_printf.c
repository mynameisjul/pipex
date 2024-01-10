/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:52 by jblaye            #+#    #+#             */
/*   Updated: 2024/01/10 19:04:23 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_type(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		ft_putcharcount_fd(&count, va_arg(ap, int), 1);
	if (c == 's')
		ft_putstrcount_fd(&count, va_arg(ap, char *), 1);
	if (c == 'd' || c == 'i')
		ft_putnbrcount_fd(&count, va_arg(ap, int), 1);
	if (c == 'u')
		ft_putuicount_fd(&count, va_arg(ap, unsigned int), 1);
	if (c == 'x')
		ft_putnbrbasecount_fd(&count, va_arg(ap, unsigned int), 1);
	if (c == 'X')
		ft_putnbrupbasecount_fd(&count, va_arg(ap, unsigned int), 1);
	if (c == '%')
		ft_putcharcount_fd(&count, '%', 1);
	if (c == 'p')
		ft_putptrcount_fd(&count, va_arg(ap, unsigned long int), 1);
	return (count);
}

int	ft_printf(const char *str, ...)
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
			write(1, &str[i], 1);
			nbc++;
		}
		i++;
	}
	return (nbc);
}
