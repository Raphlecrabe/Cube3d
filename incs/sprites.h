/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:17:33 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 10:17:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define UDIV 1
# define VDIV 1
# define VMOVE 0

# define ANIM_SPEED 1

typedef struct s_display	t_display;

typedef struct s_sprite_texture
{
	int	x;
	int	y;
	int	height;
	int	width;
	int	*fd;
	int	frame_number;
}				t_sprite_texture;

typedef struct s_sprite
{
	t_vector2			world_pos;
	t_vector2			relative_pos;
	t_vector2			transform;
	float				dist;
	t_vector2			draw_start;
	t_vector2			draw_end;
	int					on_screen_height;
	int					on_screen_width;
	int					screen_x;
	t_sprite_texture	tex;
	int					v_move_screen;
}				t_sprite;

typedef struct s_sprite_datas
{
	t_sprite	*sprites;
	int			number;
}				t_sprite_datas;

void		display_sprite(t_display *display);
void		calc_sprite_height(int screen_height, t_sprite *sprite);
void		calc_sprite_width(int screen_height, int screen_width,
		t_sprite *sprite);
int			is_drawable(t_display *display, t_sprite sprite, int x);
t_vector2	get_transform(t_display *display, float inv_det,
							t_sprite sprite);

#endif