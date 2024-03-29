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
#include "../../incs/garbage.h"
#include <stdio.h>

static float	get_height(float height, float screen_height)
{
	float	factor;

	factor = 1.0f;
	return ((factor * screen_height) / height);
}

t_stripe	get_stripe(int x, t_display *display)
{
	t_stripe	stripe;
	t_hit		hit;

	hit = raycast_hit(x, display);
	stripe.x = x;
	stripe.perp_wall_dist = hit.distance_adapted;
	stripe.height = get_height(hit.distance_adapted, display->win_size.y);
	stripe.side = hit.side;
	stripe.pos = hit.pos;
	stripe.dist = hit.true_distance;
	return (stripe);
}
