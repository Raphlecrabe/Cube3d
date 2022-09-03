/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:05:14 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 10:05:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include <stdlib.h>
#include <math.h>

t_vector2	get_step(t_raycast ray)
{
	t_vector2	step;

	if (ray.dir.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray.dir.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

t_vector2	get_side(t_raycast ray, t_vector2 pos)
{
	t_vector2	side;

	if (ray.dir.x < 0)
		side.x = (pos.x - ray.mappos.x) * ray.delta_dist.x;
	else
		side.x = (ray.mappos.x + 1 - pos.x) * ray.delta_dist.x;
	if (ray.dir.y < 0)
		side.y = (pos.y - ray.mappos.y) * ray.delta_dist.y;
	else
		side.y = (ray.mappos.y + 1 - pos.y) * ray.delta_dist.y;
	return (side);
}
