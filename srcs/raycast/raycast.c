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

#include "../../incs/raycast.h"
#include "../../incs/vectors.h"
#include "../../incs/display.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static float	get_height(int side, t_raycast ray)
{
	if (side == 0)
		return (ray.side_dist.x - ray.delta_dist.x);
	else
		return (ray.side_dist.y - ray.delta_dist.y);
}

static t_vector2 get_step(t_raycast ray)
{
	t_vector2 step;

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

static t_vector2 get_side(t_raycast ray, t_vector2 pos)
{
	t_vector2 side;

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

static t_raycast	init_ray(int x, t_display *display)
{
	t_raycast	ray;

	ray.cameraX = (float)(2 * x) / (float)display->screen_width - 1;
	ray.dir.x = display->player_dir.x + display->plane.x * ray.cameraX;
	ray.dir.y = display->player_dir.y + display->plane.y * ray.cameraX;
	ray.delta_dist.x = (ray.dir.x == 0) ? 2147483647 : fabs(1 / ray.dir.x);
	ray.delta_dist.y = (ray.dir.y == 0) ? 2147483647 : fabs(1 / ray.dir.y);
	ray.mappos = vector2((int)display->player_pos.x, (int)display->player_pos.y);
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
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->mappos.y += ray->step.y;
		hit->side = 1;
	}

	if (map->lines[(int)ray->mappos.x][(int)ray->mappos.y] == '1')
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

	hit.height = get_height(hit.side, ray);

	hit.distance = hit.height * vector2_magnitude(ray.dir);
	hit.pos = vector2_add(vector2_multiply(ray.dir, hit.height), display->player_pos);

	return (hit);
}
