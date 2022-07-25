/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbageutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:38:34 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/22 13:13:08 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cube3d.h"

char	*ft_strncopy_const(char *line, int n, char c, t_memory *mem)
{
	int		i;
	char	*copy;

	i = 0;
	copy = ft_malloc_const(sizeof(char), n + 1, mem);
	if (copy == NULL)
		return (NULL);
	while (i <= n && line[i] != '\0')
	{
		copy[i] = line[i];
		i++;
	}
	while (i <= n)
	{
		copy[i] == c;
		i++;
	}
	copy[i] = '\0';
}

t_list	*ft_lstnew_temp(void *content, t_memory *mem)
{
	t_list	*lst;

	lst = ft_malloc_temp(sizeof (*lst), 1, mem);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
