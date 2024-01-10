/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:08 by jblaye            #+#    #+#             */
/*   Updated: 2023/11/09 17:36:18 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*nxt;

	if (!f || !del || !lst)
		return (NULL);
	result = 0;
	nxt = result;
	while (lst != 0)
	{
		nxt = ft_lstnew(f(lst->content));
		if (!nxt)
		{
			ft_lstclear(&nxt, del);
			return (NULL);
		}
		ft_lstadd_back(&result, nxt);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (result);
}
