/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:21:37 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/10 20:15:08 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			lens;
	unsigned int	i;
	char			*r;

	if (!s)
		return (0);
	lens = ft_strlen(s);
	i = 0;
	r = (char *) ft_calloc((lens + 1), sizeof(char));
	if (!r)
		return (NULL);
	while (s[i] != 0)
	{
		r[i] = f(i, s[i]);
		i++;
	}
	return (r);
}
