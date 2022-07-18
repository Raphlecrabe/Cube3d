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
	printf("Displaying stripe n°%d, raycast hit a wall at distance %f\n", stripe.x, stripe.distance);
}

void	display_screen(t_map *map, t_player *player)
{
	t_stripe stripe;
	int	screen_width;
	int	x;

	x = 0;
	screen_width = 100;
	while (x < screen_width)
	{
		stripe = get_stripe(*map, *player, screen_width, x);
		display_stripe(stripe);
		x++;
	}
}