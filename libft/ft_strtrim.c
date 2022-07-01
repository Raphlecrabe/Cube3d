/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:02:34 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 14:16:30 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_inset(char const c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

static int	ft_getsize(char const *s1, char const *set)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (*s1 && ft_inset(*s1, set))
		s1++;
	while (s1[i])
	{
		s1 += i;
		size += i;
		i = 0;
		while (s1[i] && !ft_inset(s1[i], set))
			i++;
		s1 += i;
		size += i;
		i = 0;
		while (s1[i] && ft_inset(s1[i], set))
			i++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		size;

	i = -1;
	if (!s1 || !set)
		return (NULL);
	size = ft_getsize(s1, set);
	str = malloc (sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	while (*s1 && ft_inset(*s1, set))
		s1++;
	while (++i < size)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
