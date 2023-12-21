/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:54:12 by jblaye            #+#    #+#             */
/*   Updated: 2023/12/21 15:18:06 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*us;
	char	uc;
	int		i;

	us = (char *) s;
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
