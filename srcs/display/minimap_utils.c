/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:29:27 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 09:29:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minimap.h"

t_vector2	minimap_size(t_map *map)
{
	t_vector2	size;

	size.x = map->width * TILE_SIZE;
	size.y = map->heigth * TILE_SIZE;
	return (size);
}
