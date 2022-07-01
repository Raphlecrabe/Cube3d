/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:56:56 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/08/24 22:04:13 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	if (dest < src)
	{
		i = -1;
		while (++i < (int)n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else if (dest > src)
	{
		i = n;
		while (--i >= 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
