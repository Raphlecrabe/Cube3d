/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:58:04 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 13:34:13 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	if (!s)
		return (NULL);
	s2 = (unsigned char *)s;
	i = 0;
	while (s2[i] != (unsigned char)c && i + 1 < n)
		i++;
	if (s2[i] == (unsigned char)c && n != 0)
		return ((void *)(s + i));
	return (NULL);
}
