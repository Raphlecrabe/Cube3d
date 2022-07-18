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
#include <stdio.h>
#include <stdlib.h>

static float	get_distance(int side, t_raycast ray)
{
	if (side == 0)
		return (ray.side_dist.x - ray.delta_dist.x);
	else
		return (ray.side_dist.y - ray.delta_dist.y);
}

static t_vector2 *calc_step_and_sidedist(t_raycast ray, t_vector2 pos)
{
	t_vector2 *stepside;

	stepside = malloc(sizeof(t_vector2) * 2);

	if (ray.dir.x < 0)
	{
		stepside[0].x = -1;
		stepside[1].x = (pos.x - ray.pos.x) * ray.delta_dist.x;
	}
	else
	{
		stepside[0].x = 1;
		stepside[1].x = (ray.pos.x + 1 - pos.x) * ray.delta_dist.x;
	}

	if (ray.dir.y < 0)
	{
		stepside[0].y = -1;
		stepside[1].y = (pos.y - ray.pos.y) * ray.delta_dist.y;
	}
	else
	{
		stepside[0].y = 1;
		stepside[1].y = (ray.pos.y + 1 - pos.y) * ray.delta_dist.y;
	}

	return (stepside);
}

static t_raycast	init_ray(int x, int screen_width, t_vector2 pos, t_vector2 player_dir, t_vector2 plane)
{
	t_raycast	ray;
	t_vector2	*stepside;

	ray.cameraX = 2 * x / screen_width - 1;
	ray.dir = 	vector2(player_dir.x + plane.x * ray.cameraX,
						player_dir.y + plane.y * ray.cameraX);	
	ray.pos = vector2((int)pos.x, (int)pos.y);
	ray.delta_dist = vector2(0, 0);
	ray.perpWall_dist = 0;
	
	stepside = calc_step_and_sidedist(ray, pos);

	ray.step = stepside[0];
	ray.side_dist = stepside[1];

	return (ray);
}

static void	check_hit(t_hit *hit, t_map map, t_raycast *ray)
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

	printf("check: %d, %d\n", (int)ray->pos.x, (int)ray->pos.y);

	if (map.map[(int)ray->pos.x][(int)ray->pos.y] > 0)
		hit->hit = 1;
}

t_hit	raycast_hit(t_map map, t_vector2 pos, t_vector2 player_dir, t_vector2 plane, int screen_width, int x)
{
	t_hit		hit;
	t_raycast	ray;

	hit.hit = 0;
	ray = init_ray(x, screen_width, pos, player_dir, plane);

	while (hit.hit == 0)
		check_hit(&hit, map, &ray);

	hit.distance = get_distance(hit.side, ray);

	return (hit);
}