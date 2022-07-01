/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:58:26 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/08/24 21:58:28 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!ft_strncmp(s2, "", 1))
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s1[i + j] && i + j < n && s1[i + j] == s2[j])
				j++;
			if (!s2[j])
				return ((char *)&s1[i]);
			i++;
		}
		else
			i++;
	}
	return (NULL);
}
