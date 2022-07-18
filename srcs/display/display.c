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
#include <stdio.h>

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
		x++;
	}

	printf("|\n");
}