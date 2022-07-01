/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecoll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:23:04 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/01 13:28:39 by rmonacho         ###   ########lyon.fr   */
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
