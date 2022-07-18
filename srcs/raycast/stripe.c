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
#include <stdio.h>

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

t_stripe	get_stripe(int x, t_display *display)
{
	t_stripe 	stripe;
	t_hit		hit;

	hit = raycast_hit(x, display);

	stripe.x = x;
	stripe.distance = hit.distance;
	stripe.sprite = get_sprite(hit.side);
	stripe.pos = hit.pos;

	return (stripe);
}