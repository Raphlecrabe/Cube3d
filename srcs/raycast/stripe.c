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

#include "../../display.h"
#include "../../raycast.h"
#include "../../vectors.h"

t_stripe	get_stripe(t_map map, t_player player, int x)
{
	t_stripe 	stripe;
	t_hit		hit;

	hit = raycast_hit(map, x);

	stripe.x = x;
	stripe.distance = hit.distance;
	stripe.sprite = get_sprite(hit.side);

	return (stripe);
}

void	*get_sprite(int side)
{
	t_wallcolor wall;

	if (side == 0)
		wall.color = COLOR_WHITE;
	else if (side == 1)
		wall.color = WALL_BLUE;
	else if (side == 2)
		wall.color = WALL_GREEN;
	else
		wall.color = WALL_RED;
	
	return (&wall);
}