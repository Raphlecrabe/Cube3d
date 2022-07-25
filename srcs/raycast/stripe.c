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

static void	*get_sprite(int side, t_memory *mem)
{
	t_wallcolor *wall;

	wall = ft_malloc_temp(1, sizeof(t_wallcolor), mem);
	if (wall == NULL)
		return (NULL);
	if (side == 0)
		wall->color = COLOR_WHITE;
	if (side == 1)
		wall->color = COLOR_BLUE;
	if (side == 2)
		wall->color = COLOR_GREEN;
	if (side == 3)
		wall->color = COLOR_RED;
	
	return (wall);
}

t_stripe	get_stripe(int x, t_display *display)
{
	t_stripe 	stripe;
	t_hit		hit;

	hit = raycast_hit(x, display);

	stripe.x = x;
	stripe.distance = hit.distance;
	stripe.sprite = get_sprite(hit.side, display->mem);
	stripe.pos = hit.pos;

	return (stripe);
}