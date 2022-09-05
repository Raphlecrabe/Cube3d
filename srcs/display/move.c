/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:49:18 by fbelthoi          #+#    #+#             */
/*   Updated: 2022/09/05 10:46:05 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cube3d.h"
#include "../../incs/display.h"
#include "../../incs/events.h"
#include "../../incs/minimap.h"
#include <stdio.h>
#include <mlx.h>
#include <math.h>

static int	other_key(int keycode, t_display *display)
{
	//printf("%d\n", keycode);
	if (keycode == ESCAPE_KEY_MAC)
		return (0);
	return (1);
}

static int	col(t_collision collision, t_vector2 direction)
{
	t_vector2	point;
	t_vector2	final_pos;
	t_vector2	orthog_vector;
	t_vector2	buffer;
	float		right_angle;

	right_angle = 90.0f;
	buffer = vector2_multiply(vector2_normalize(direction),
			collision.screenplane_width / 3);
	direction = vector2_add(direction, buffer);
	orthog_vector = vector2_rotate(direction, right_angle * DEG_TO_RAD);
	final_pos = vector2_add(collision.player_pos, direction);
	point = final_pos;
	if (is_wall(collision.map->lines[(int)point.y][(int)point.x]))
		return (1);
	point = vector2_add(final_pos, orthog_vector);
	if (is_wall(collision.map->lines[(int)point.y][(int)point.x]))
		return (1);
	point = vector2_substract(final_pos, orthog_vector);
	if (is_wall(collision.map->lines[(int)point.y][(int)point.x]))
		return (1);
	return (0);
}

static t_collision	init_collision(t_display *display, float movespeed)
{
	t_collision	collision;

	collision.player_pos = display->player_pos;
	collision.movespeed = movespeed;
	collision.screenplane_width = vector2_magnitude(display->plane);
	collision.map = display->map;
	return (collision);
}

static int	key_affect(int keycode, t_display *display)
{
	t_vector2	direction;
	t_vector2	null;
	t_collision	collision;

	null = vector2(0, 0);
	direction = null;
	collision = init_collision(display, MOVE_SPEED);
	if (keycode == LEFT_KEY_MAC)
		rotate_player(display, -ROTATE_SPEED * DEG_TO_RAD);
	else if (keycode == RIGHT_KEY_MAC)
		rotate_player(display, ROTATE_SPEED * DEG_TO_RAD);
	else if (keycode == W_KEY_MAC || keycode == Z_KEY_MAC)
		direction = vector2_multiply(display->player_dir, MOVE_SPEED);
	else if (keycode == S_KEY_MAC)
		direction = vector2_multiply(display->player_dir, -MOVE_SPEED);
	else if (keycode == Q_KEY_MAC || keycode == A_KEY_MAC)
		direction = vector2_multiply(display->plane, -MOVE_SPEED);
	else if (keycode == D_KEY_MAC)
		direction = vector2_multiply(display->plane, MOVE_SPEED);
	else
		return (other_key(keycode, display));
	if (!vector2_equals(direction, null) && !col(collision, direction))
		move(display, direction);
	return (1);
}

int	key_hook(int keycode, t_display *display)
{
	if (key_affect(keycode, display))
		if (display_all(display))
			return (1);
	exit_cub(display);
	return (0);
}
