/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:57:05 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 13:35:20 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		src_length;

	i = -1;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (size == 0)
		return (src_length);
	while (++i + 1 < size && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (src_length);
}
