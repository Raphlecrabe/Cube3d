/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbageutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:38:34 by rmonacho          #+#    #+#             */
/*   Updated: 2023/02/08 17:45:36 by marvin           ###   ########.fr       */
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
	while (i < n)
	{
		copy[i] = c;
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup_temp(const char *s, t_memory *mem)
{
	int		i;
	size_t	slen;
	char	*scpy;

	i = -1;
	slen = 0;
	if (!s)
		return (NULL);
	while (s[slen])
		slen++;
	scpy = ft_malloc_temp(sizeof(char), (slen + 1), mem);
	if (!scpy)
		return (NULL);
	while (++i < (int)slen)
		scpy[i] = s[i];
	scpy[slen] = '\0';
	return (scpy);
}

t_list	*ft_lstnew_temp(void *content, t_memory *mem)
{
	t_list	*lst;

	lst = ft_malloc_temp(sizeof(t_list), 1, mem);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
