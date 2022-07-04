/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecoll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:23:04 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/04 14:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

void	*ft_malloc(size_t memory, size_t size)
{
	void	*array;

	array = ft_calloc(memory, size);
	if (array == NULL)
		return (NULL);
	return (array);
}

void	ft_to_free(void *p)
{
	free(p);
}