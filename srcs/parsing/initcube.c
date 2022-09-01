/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:43:16 by rmonacho          #+#    #+#             */
/*   Updated: 2022/09/01 14:02:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_initcube(t_cube **cube, t_memory *mem)
{
	(*cube) = ft_malloc_const(1, sizeof(t_cube), mem);
	if ((*cube) == NULL)
		return (-1);
	(*cube)->mem = mem;
	(*cube)->map = NULL;
	(*cube)->playerinit = ft_malloc_const(1, sizeof(t_playerinit), mem);
	if ((*cube)->playerinit == NULL)
		return (-1);
	(*cube)->west = NULL;
	(*cube)->east = NULL;
	(*cube)->north = NULL;
	(*cube)->south = NULL;
	(*cube)->fd = 0;
	(*cube)->ceiling = 0;
	(*cube)->floor = 0;
	(*cube)->parsed = 0;
	(*cube)->path = NULL;
	(*cube)->check.pfloor = 0;
	(*cube)->check.pceil = 0;
	(*cube)->check.pwest = 0;
	(*cube)->check.peast = 0;
	(*cube)->check.psouth = 0;
	(*cube)->check.pnorth = 0;
	(*cube)->check.player = 0;
	return (0);
}
