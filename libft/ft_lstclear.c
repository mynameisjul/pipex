/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:46:39 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/10 15:18:20 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*l;

	l = *lst;
	if (lst && *lst && del)
	{
		while (l != 0)
		{
			nxt = l->next;
			ft_lstdelone(l, del);
			l = nxt;
		}
		*lst = NULL;
	}
}
