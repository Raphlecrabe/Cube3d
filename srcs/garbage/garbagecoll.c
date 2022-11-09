/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecoll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:23:04 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/09 13:00:54 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../incs/parsing.h"
#include "../../incs/garbage.h"
#include <stdio.h>

void	*ft_malloc(size_t memory, size_t size)
{
	void	*p;

	p = ft_calloc(memory, size);
	if (p == NULL)
		return (NULL);
	return (p);
}

void	*ft_malloc_const(size_t memory, size_t size, t_memory *mem)
{
	void	*p;
	t_list	*lst;

	p = ft_calloc(memory, size);
	if (p == NULL)
		return (NULL);
	lst = ft_lstnew(p);
	if (lst == NULL)
	{
		free(p);
		return (NULL);
	}
	ft_lstadd_back(&(mem->used), lst);
	return (p);
}

void	*ft_malloc_temp(size_t memory, size_t size, t_memory *mem)
{
	void	*p;
	t_list	*lst;

	p = ft_calloc(memory, size);
	if (p == NULL)
		return (NULL);
	lst = ft_lstnew((void *)tag(p));
	if (lst == NULL)
	{
		free(p);
		return (NULL);
	}
	ft_lstadd_back(&(mem->used), lst);
	return (p);
}

void	ft_freetemp(t_memory *mem)
{
	t_list	*prev;
	t_list	*next;
	t_list	*lst;

	prev = NULL;
	lst = mem->used;
	while (lst)
	{
		next = lst->next;
		if (tagged(lst->content))
		{
			lst->content = (void *)untag(lst->content);
			ft_lstdelone(lst, &ft_lstdel);
			lst = NULL;
			if (prev)
				prev->next = next;
			else
				mem->used = next;
		}
		else
			prev = lst;
		lst = next;
	}
}

void	ft_freemem(t_memory *mem)
{
	ft_freetemp(mem);
	ft_lstclear(&(mem->used), &ft_lstdel);
}
