/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:30:35 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/08 12:00:19 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	getcountnbr(int n)
{
	int	count;

	count = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char		*r;
	long int	nbr;
	int			count;

	nbr = (long int) n;
	count = getcountnbr(nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	r = (char *) ft_calloc((count + 1), sizeof(char));
	if (!r)
		return (NULL);
	r[0] = '-';
	r[count] = '\0';
	count--;
	while (nbr >= 10)
	{
		r[count] = nbr % 10 + '0';
		nbr = nbr / 10;
		count--;
	}
	r[count] = nbr + '0';
	return (r);
}
