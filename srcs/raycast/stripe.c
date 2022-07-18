/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:03:18 by marvin            #+#    #+#             */
/*   Updated: 2022/07/04 16:03:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/raycast.h"
#include "../../incs/vectors.h"

void	*get_sprite(int side)
{
	t_wallcolor wall;

	if (side == 0)
		wall.color = COLOR_WHITE;
	if (side == 1)
		wall.color = COLOR_BLUE;
	if (side == 2)
		wall.color = COLOR_GREEN;
	if (side == 3)
		wall.color = COLOR_RED;
	
	void *p = &wall;
	return (p);
}

t_stripe	get_stripe(t_map map, t_player player, int screen_width, int x)
{
	t_stripe 	stripe;
	t_hit		hit;

	t_vector2 pos = vector2(player.x, player.y);
	t_vector2 dir = vector2(0, 1);
	t_vector2 plane = vector2(1, 0);

	hit = raycast_hit(map, pos, dir, plane, screen_width, x);

	stripe.x = x;
	stripe.distance = hit.distance;
	stripe.sprite = get_sprite(hit.side);

	return (stripe);
}