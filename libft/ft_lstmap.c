/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:24:17 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 14:52:46 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_iter;
	t_list	*new_elem;
	t_list	*lst_adr;

	if (!lst || !f)
		return (NULL);
	lst_adr = lst;
	lst_iter = NULL;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&lst_adr, del);
			ft_lstclear(&lst_iter, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_iter, new_elem);
		lst = lst->next;
	}
	return (lst_iter);
}
