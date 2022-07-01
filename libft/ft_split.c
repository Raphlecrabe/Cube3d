/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:15:52 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/11/04 15:22:17 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_allocstr(char const *s, char c)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = malloc (sizeof (*str) * (len + 1));
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

static char	**ft_freeall(char **tab, int index)
{
	index++;
	while (--index >= 0)
		free(tab[index]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		size;
	int		tab_index;

	if (!s)
		return (NULL);
	size = ft_getsize(s, c);
	tab = malloc (sizeof (*tab) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tab_index = -1;
	while (++tab_index < size)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[tab_index] = ft_allocstr(s + i, c);
		if (!tab[tab_index])
			return (ft_freeall(tab, tab_index));
		while (s[i] && s[i] != c)
			i++;
	}
	tab[tab_index] = NULL;
	return (tab);
}
