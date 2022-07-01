/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:58:18 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 13:34:31 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	if (!s1 || !s2 || !n)
		return (0);
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (string1[i] == string2[i] && i + 1 < n)
		i++;
	return (string1[i] - string2[i]);
}
