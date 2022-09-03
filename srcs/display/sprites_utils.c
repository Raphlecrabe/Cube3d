/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:53:46 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 09:53:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/garbage.h"
#include "../../incs/mlx_utils.h"
#include <math.h>

void	calc_sprite_height(int screen_height, t_sprite *sprite)
{
	int			height;
	int			draw_start_y;
	int			draw_end_y;

	height = (int)fabs(screen_height / sprite->transform.y) / VDIV;
	draw_start_y = -height / 2 + screen_height / 2 + sprite->v_move_screen;
	if (draw_start_y < 0)
		draw_start_y = 0;
	draw_end_y = height / 2 + screen_height / 2 + sprite->v_move_screen;
	if (draw_end_y >= screen_height)
		draw_end_y = screen_height - 1;
	sprite->on_screen_height = height;
	sprite->draw_start.y = draw_start_y;
	sprite->draw_end.y = draw_end_y;
}

void	calc_sprite_width(int screen_height, int screen_width,
		t_sprite *sprite)
{
	int			width;
	int			draw_start_x;
	int			draw_end_x;

	width = (int)fabs(screen_height / sprite->transform.y) / UDIV;
	draw_start_x = -width / 2 + sprite->screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	draw_end_x = width / 2 + sprite->screen_x;
	if (draw_end_x >= screen_width)
		draw_end_x = screen_width - 1;
	sprite->on_screen_width = width;
	sprite->draw_start.x = draw_start_x;
	sprite->draw_end.x = draw_end_x;
}

int	is_drawable(t_display *display, t_sprite sprite, int x)
{
	// if
	// it's in front of camera plane so you don't see things behind you
	// it's on the screen (left)
	// it's on the screen (right)
	// z_buffer, with perpendicular distance
	return (sprite.transform.y > 0
		&& x > 0
		&& x < display->screen_width
		&& sprite.transform.y < display->z_buffer[x]);
}

t_vector2	get_transform(t_display *display, float inv_det,
							t_sprite sprite)
{
	t_vector2	transform;
	t_vector2	dir;
	t_vector2	plane;
	t_vector2	sprite_pos;

	dir = display->player_dir;
	plane = display->plane;
	sprite_pos = sprite.relative_pos;
	transform.x = inv_det * (dir.y * sprite_pos.x - dir.x * sprite_pos.y);
	transform.y = inv_det * (-plane.y * sprite_pos.x + plane.x * sprite_pos.y);
	return (transform);
}
