/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:49:18 by fbelthoi          #+#    #+#             */
/*   Updated: 2022/07/22 14:09:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cube3d.h"
#include "../../incs/display.h"
#include "../../incs/events.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>

static void	rotate_left(t_display *display, float angle)
{
	float oldDirX = display->player_dir.x;
	display->player_dir.x = display->player_dir.x * cos(angle) - display->player_dir.y * sin(angle);
	display->player_dir.y = oldDirX * sin(angle) + display->player_dir.y * cos(angle);

	float oldPlaneX = display->plane.x;
	display->plane.x = display->plane.x * cos(angle) - display->plane.y * sin(angle);
	display->plane.y = oldPlaneX * sin(angle) + display->plane.y * cos(angle);
}

static void	rotate_right(t_display *display, float angle)
{
	float oldDirX = display->player_dir.x;
	display->player_dir.x = display->player_dir.x * cos(-angle) - display->player_dir.y * sin(-angle);
	display->player_dir.y = oldDirX * sin(-angle) + display->player_dir.y * cos(-angle);

	float oldPlaneX = display->plane.x;
	display->plane.x = display->plane.x * cos(-angle) - display->plane.y * sin(-angle);
	display->plane.y = oldPlaneX * sin(-angle) + display->plane.y * cos(-angle);
}

void	key_affect(int keycode, t_display *display)
{
	float rotate_speed = 0.1;

	if (keycode == Q_KEY_LIN)
		rotate_left(display, rotate_speed);
	else if (keycode == D_KEY_LIN)
		rotate_right(display, rotate_speed);
}

int key_hook(int keycode, t_display *display)
{
	key_affect(keycode, display);

	display_screen(display);

	return (0);
}