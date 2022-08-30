/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:49:18 by fbelthoi          #+#    #+#             */
/*   Updated: 2022/08/16 15:22:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../incs/cube3d.h"
#include "../../incs/display.h"
#include "../../incs/events.h"
#include "../../incs/minimap.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>

void	rotate(t_display *display, float angle)
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

static int	col(t_collision collision, t_vector2 mvfactors, t_vector2 osfactors)
{
	t_vector2	pos;
	t_vector2	mvvector;
	t_vector2	osvector;
	float		dist;

	dist = collision.movespeed + collision.screenplane_width / 2;
	mvvector = vector2_multiply(mvfactors, dist);
	osvector = vector2_multiply(osfactors, collision.screenplane_width / 2);

	pos = vector2_add(collision.player_pos, mvvector);
	if (collision.map->lines[(int)pos.x][(int)pos.y] == '1')
		return (1);
	pos = vector2_add(vector2_add(collision.player_pos, osvector), mvvector);
	if (collision.map->lines[(int)pos.x][(int)pos.y] == '1')
		return (1);
	pos = vector2_add(vector2_substract(collision.player_pos, osvector), mvvector);
	if (collision.map->lines[(int)pos.x][(int)pos.y] == '1')
		return (1);
	return (0);
}

t_collision	init_collision(t_display *display, float movespeed)
{
	t_collision collision;

	collision.player_pos = display->player_pos;
	collision.movespeed = movespeed;
	collision.screenplane_width = vector2_magnitude(display->plane);
	collision.map = display->map;

	return (collision);
}

void	key_affect(int keycode, t_display *display)
{
	float		rotate_speed;
	float		movespeed;
	t_collision	collision;

	rotate_speed = ROTATE_SPEED;
	movespeed = MOVE_SPEED;
	collision = init_collision(display, movespeed);
	if (keycode == Q_KEY_LIN)
		rotate(display, -rotate_speed);
	else if (keycode == D_KEY_LIN)
		rotate(display, rotate_speed);
	else if (keycode == UP_KEY_LIN && !col(collision, vector2(0, -1), vector2(1, 0)))
		display->player_pos.y -= movespeed;
	else if (keycode == DOWN_KEY_LIN && !col(collision, vector2(0, 1), vector2(1, 0)))
		display->player_pos.y += movespeed;
	else if (keycode == LEFT_KEY_LIN && !col(collision, vector2(-1, 0), vector2(0, 1)))
		display->player_pos.x -= movespeed;
	else if (keycode == RIGHT_KEY_LIN && !col(collision, vector2(1, 0), vector2(0, 1)))
		display->player_pos.x += movespeed;
}

int	key_hook(int keycode, t_display *display)
{
	key_affect(keycode, display);
	if (!display_screen(display))
		return (0);
	display_minimap(display);
	//ft_freetemp(display->mem);
	return (1);
}
