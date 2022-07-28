/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:49:18 by fbelthoi          #+#    #+#             */
/*   Updated: 2022/07/28 23:22:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cube3d.h"
#include "../../incs/display.h"
#include "../../incs/events.h"
#include "../../incs/minimap.h"
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
	float rotate_speed = 0.1f;
	float movespeed = 0.1f;
	t_vector2 pos = display->player_pos;

	if (keycode == Q_KEY_LIN)
		rotate_left(display, rotate_speed);
	else if (keycode == D_KEY_LIN)
		rotate_right(display, rotate_speed);
	else if (keycode == UP_KEY_LIN && pos.y > 0)
		pos.y -= movespeed;
	else if (keycode == DOWN_KEY_LIN && pos.y < 23)
		pos.y += movespeed;
	else if (keycode == LEFT_KEY_LIN && pos.x > 0)
		pos.x -= movespeed;
	else if (keycode == RIGHT_KEY_LIN && pos.x < 23)
		pos.x += movespeed;

	display->player_pos = pos;
}

int key_hook(int keycode, t_display *display)
{
	key_affect(keycode, display);

	mlx_destroy_image(display->mlx, display->datas->img);

	display->datas->img = mlx_new_image(display->mlx, display->datas->win_size.x, display->datas->win_size.y);
	display->datas->addr = mlx_get_data_addr(display->datas->img, &display->datas->bits_per_pixel, &display->datas->line_length, &display->datas->endian);

	minimap_display(display);

	display_screen(display);

	mlx_put_image_to_window(display->mlx, display->mlx_win, display->datas->img, 0, 0);

	return (0);
}
