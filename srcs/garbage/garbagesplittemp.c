/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagesplittemp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:07:44 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/21 17:10:36 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../incs/cube3d.h"

static char	*ft_allocstr(char const *s, char c, t_memory *mem)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = ft_malloc_temp(sizeof (*str), (len + 1), mem);
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

static int	ft_getsize(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

char	**ft_split_temp(char const *s, char c, t_memory *mem)
{
	char	**tab;
	int		i;
	int		size;
	int		tab_index;

	if (!s)
		return (NULL);
	size = ft_getsize(s, c);
	tab = ft_malloc_temp(sizeof (*tab), (size + 1), mem);
	if (!tab)
		return (NULL);
	i = 0;
	tab_index = -1;
	while (++tab_index < size)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[tab_index] = ft_allocstr(s + i, c, mem);
		if (!tab[tab_index])
			return (NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[tab_index] = NULL;
	return (tab);
}
