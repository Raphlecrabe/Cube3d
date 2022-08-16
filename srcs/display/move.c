/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:49:18 by fbelthoi          #+#    #+#             */
/*   Updated: 2022/08/16 14:58:23 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cube3d.h"
#include "../../incs/display.h"
#include "../../incs/events.h"
#include "../../incs/minimap.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>

static void	rotate(t_display *display, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = display->player_dir.x;
	display->player_dir.x = display->player_dir.x * cos(angle)
		- display->player_dir.y * sin(angle);
	display->player_dir.y = old_dir_x * sin(angle)
		+ display->player_dir.y * cos(angle);
	old_plane_x = display->plane.x;
	display->plane.x = display->plane.x * cos(angle)
		- display->plane.y * sin(angle);
	display->plane.y = old_plane_x * sin(angle)
		+ display->plane.y * cos(angle);
}

int	col(float x, float y, t_map *map)
{
	if (map->lines[(int)x][(int)y] == '1')
		return (1);
	else
		return (0);
}

void	key_affect(int keycode, t_display *display)
{
	float		rotate_speed;
	float		movespeed;
	t_vector2	pos;
	t_map		*map;

	rotate_speed = ROTATE_SPEED;
	movespeed = MOVE_SPEED;
	pos = display->player_pos;
	map = display->map;
	if (keycode == Q_KEY_LIN)
		rotate(display, -rotate_speed);
	else if (keycode == D_KEY_LIN)
		rotate(display, rotate_speed);
	else if (keycode == UP_KEY_LIN && !col(pos.x, pos.y - movespeed, map))
		pos.y -= movespeed;
	else if (keycode == DOWN_KEY_LIN && !col(pos.x, pos.y + movespeed, map))
		pos.y += movespeed;
	else if (keycode == LEFT_KEY_LIN && !col(pos.x - movespeed, pos.y, map))
		pos.x -= movespeed;
	else if (keycode == RIGHT_KEY_LIN && !col(pos.x + movespeed, pos.y, map))
		pos.x += movespeed;
	display->player_pos = pos;
}

int	key_hook(int keycode, t_display *display)
{
	key_affect(keycode, display);
	if (!display_screen(display))
		return (0);
	minimap_display(display);
	//ft_freetemp(display->mem);
	return (1);
}
