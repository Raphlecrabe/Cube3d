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

#include "../../raycast.h"
#include "../../vectors.h"

static float	get_distance(int side, t_raycast ray)
{
	if (side == 0)
		return (ray.side_dist.x - ray.delta_dist.x);
	else
		return (ray.side_dist.y - ray.delta_dist.y);
}

static t_raycast	init_ray()
{
	t_raycast	ray;

	ray.cameraX = 2 * x / double(screen_width) - 1;
	ray.dir = 	vector2(player_dir.x + plane.x * cameraX,
						player_dir.y + plane.y * cameraX);
	ray.pos =	vector2((int)pos.x, (int)pos.y);
	ray.side_dist = vector2(0, 0);
	ray.delta_dist = vector2(0, 0);
	ray.perpWall_dist = 0;
	ray.step = vector2(0, 0);

	return (ray);
}

static void	hit(t_hit *hit, t_map map, t_raycast *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->pos.x += ray->step.x;
		hit->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->pos.y += ray->step.y;
		hit->side = 1;
	}

	if (map[ray.pos.x][ray.pos.y] > 0)
		hit->hit = 1;
}

t_hit	raycast_hit(t_map map, t_vector2 pos, t_vector2 player_dir, t_vector2 plane, int screen_width, int x)
{
	t_hit		hit;
	t_raycast	ray;

	hit.hit = 0;
	ray = init_ray();

	while (hit.hit == 0)
		hit(&hit, map, &ray)

	hit.distance = get_distance(hit.side, ray);

	return (hit);
}