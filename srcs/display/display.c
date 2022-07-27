/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:57:39 by marvin            #+#    #+#             */
/*   Updated: 2022/07/04 15:57:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/raycast.h"
#include "../../incs/mlx_utils.h"
#include "../../incs/vectors.h"
#include "../../incs/minimap.h"
#include <mlx.h>
#include <stdio.h>

static void trace_raycast(t_display *display, t_vector2 hitpos)
{
	//t_vector2 factor = vector2(TILE_SIZE, TILE_SIZE);

	t_vector2 player2screen = vector2_multiply(display->player_pos, TILE_SIZE);
	t_vector2 ray2screen = vector2_multiply(hitpos, TILE_SIZE);
	
	draw_line(display->datas, player2screen, ray2screen, 0x0000FF00);
	mlx_put_image_to_window(display->mlx, display->mlx_win, display->datas->img, 0, 0);
}

static void	display_stripe(t_stripe stripe)
{
	printf("|%.1f", stripe.distance);
	//printf("Displaying stripe n°%d, raycast hit a wall at position %d, %d\n", stripe.x, (int)stripe.pos.x, (int)stripe.pos.y);
}

void	display_screen(t_display *display)
{
	t_stripe 	stripe;
	int			x;

	x = 0;
	while (x < display->screen_width)
	{
		stripe = get_stripe(x, display);
		display_stripe(stripe);
		trace_raycast(display, stripe.pos);
		x++;
	}

	//trace_raycast(display, stripe.pos);

	printf("|\n");
}
