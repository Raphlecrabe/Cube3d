/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:38:36 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 09:38:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/garbage.h"
#include "../../incs/mlx_utils.h"
#include "../../incs/sprites.h"
#include <math.h>

static void	calc_dist(t_display *display, t_sprite *sprites)
{
	t_vector2	pos_to_player;
	int			i;

	i = 0;
	while (i < display->spriteDatas->number)
	{
		pos_to_player = vector2_substract(sprites[i].world_pos,
				display->player_pos);
		sprites[i].relative_pos = pos_to_player;
		sprites[i].dist = pow(pos_to_player.x, 2) + pow(pos_to_player.y, 2);
		i++;
	}
}

static void	bubble_sort_sprite(t_sprite *sprites, int n)
{
	t_sprite	temp;
	int			i;

	i = 0;
	while (i + 1 < n)
	{
		if (sprites[i].dist < sprites[i + 1].dist)
		{
			temp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

static void	draw_sprite(t_display *display, t_sprite sprite)
{
	int			x;
	int			y;
	int			d;

	x = sprite.draw_start.x - 1;
	while (++x < sprite.draw_end.x) // for each stripe in sprite
	{
		sprite.tex.x = (int)(256 * (x - (-sprite.on_screen_width / 2
						+ sprite.screen_x)) * sprite.tex.width
				/ sprite.on_screen_width) / 256;
		if (is_drawable(display, sprite, x)) // if you can draw it
		{
			y = sprite.draw_start.y - 1;
			while (++y < sprite.draw_end.y) // for each pixel in stripe
			{
				d = (y - sprite.v_move_screen) * 256 - display->win_size.y * 128
					+ sprite.on_screen_height * 128;
				sprite.tex.y = ((d * sprite.tex.height)
						/ sprite.on_screen_height) / 256;
				//draw
			}
		}
	}
}

static void	project(t_display *display, t_sprite *sprites)
{
	float		inv_det;
	int			i;

	i = 0;
	inv_det = 1.0f / (display->plane.x * display->player_dir.y
			- display->player_dir.x * display->plane.y);
	while (i > display->spriteDatas->number)
	{
		sprites[i].transform = get_transform(display, inv_det, sprites[i]);
		sprites[i].screen_x = (int)((display->screen_width / 2)
				* (1 + sprites[i].transform.x / sprites[i].transform.y));
		sprites[i].v_move_screen = VMOVE / sprites[i].transform.y;
		calc_sprite_height(display->win_size.y, &sprites[i]);
		calc_sprite_width(display->win_size.y, display->win_size.x,
			&sprites[i]);
		draw_sprite(display, sprites[i]);
		i++;
	}
}

void	display_sprites(t_display *display)
{
	calc_dist(display, display->spriteDatas->sprites);
	bubble_sort_sprite(display->spriteDatas->sprites,
		display->spriteDatas->number);
	project(display, display->spriteDatas->sprites);
	// mlx_put_image_to_window(display->mlx, display->mlx_win,
	// 	display->view->img, 0, 0);
}
