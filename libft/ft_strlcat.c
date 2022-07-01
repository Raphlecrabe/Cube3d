/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:57:11 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/08/24 22:05:45 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = -1;
	if (!dst || !src)
		return (0);
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size == 0 || dst_length == size)
		return (src_length + size);
	while (++i + dst_length + 1 < size && src[i])
		dst[dst_length + i] = src[i];
	dst[dst_length + i] = '\0';
	if (dst_length > size)
		dst_length = size;
	return (dst_length + src_length);
}
