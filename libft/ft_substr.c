/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:11 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/10 19:43:21 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		lenr;
	int		i;
	char	*r;

	if (!s)
		return (0);
	lenr = ft_strlen(s) - start;
	i = 0;
	if (lenr < 0)
		return (ft_calloc(1, sizeof(char)));
	if (lenr > (int) len)
		lenr = len;
	r = (char *) ft_calloc((lenr + 1), sizeof(char));
	if (!r)
		return (NULL);
	while (len > 0 && s[start + i] != 0)
	{
		r[i] = s[start + i];
		i++;
		len--;
	}
	r[i] = '\0';
	return (r);
}
