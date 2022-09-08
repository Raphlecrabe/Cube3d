/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:03:13 by marvin            #+#    #+#             */
/*   Updated: 2022/07/04 16:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include <stdlib.h>
#include <math.h>

static float	get_distance(int side, t_raycast ray)
{
	if (side == 0 || side == 2)
		return (ray.side_dist.x - ray.delta_dist.x);
	else
		return (ray.side_dist.y - ray.delta_dist.y);
}

static t_raycast	init_ray(int x, t_display *display)
{
	t_raycast	ray;

	ray.camera_x = (float)(2 * x) / (float)display->screen_width - 1;
	ray.dir.x = display->player_dir.x + display->plane.x * ray.camera_x;
	ray.dir.y = display->player_dir.y + display->plane.y * ray.camera_x;
	if (ray.dir.x == 0)
		ray.delta_dist.x = 2147483647;
	else
		ray.delta_dist.x = fabs(1 / ray.dir.x);
	if (ray.dir.y == 0)
		ray.delta_dist.y = 2147483647;
	else
		ray.delta_dist.y = fabs(1 / ray.dir.y);
	ray.mappos = vector2((int)display->player_pos.x,
			(int)display->player_pos.y);
	ray.step = get_step(ray);
	ray.side_dist = get_side(ray, display->player_pos);
	return (ray);
}

static void	check_hit(t_hit *hit, t_map *map, t_raycast *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->mappos.x += ray->step.x;
		hit->side = 0;
		if (ray->step.x < 0)
			hit->side = 2;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->mappos.y += ray->step.y;
		hit->side = 1;
		if (ray->step.y < 0)
			hit->side = 3;
	}
	if (map->lines[(int)ray->mappos.y][(int)ray->mappos.x] == '1')
		hit->hit = 1;
}

t_hit	raycast_hit(int x, t_display *display)
{
	t_hit		hit;
	t_raycast	ray;

	ray = init_ray(x, display);
	hit.hit = 0;
	while (hit.hit == 0)
		check_hit(&hit, display->map, &ray);
	hit.distance_adapted = get_distance(hit.side, ray);
	hit.true_distance = hit.distance_adapted * vector2_magnitude(ray.dir);
	hit.pos = vector2_add(vector2_multiply(ray.dir, hit.distance_adapted),
			display->player_pos);
	return (hit);
}
