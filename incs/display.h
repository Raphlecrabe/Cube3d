/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:30:43 by raphael           #+#    #+#             */
/*   Updated: 2022/08/15 13:30:43 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "cube3d.h"
# include "vectors.h"
# include "garbage.h"
# include "mlx_utils.h"
# include "raycast.h"
# include "events.h"
# include "minimap.h"
# include "events.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

# define SHADE 0

typedef struct s_calc
{
	int		widthwall;
	float	relativepos;
	int		ytext;
	int		height;
	int		color;
}	t_calc;

typedef struct s_texture
{
	char		*west;
	char		*east;
	char		*north;
	char		*south;
	int			ceiling;
	int			floor;
	int			shade;
	t_mlx_datas	*wtext;
	t_mlx_datas	*etext;
	t_mlx_datas	*ntext;
	t_mlx_datas	*stext;
	t_mlx_datas	*first;
	t_mlx_datas	*second;
	t_mlx_datas	*third;
}				t_texture;

typedef struct s_display
{
	void		*mlx;
	void		*mlx_win;
	t_vector2	win_size;
	t_mlx_datas	*view;
	t_mlx_datas	*minimap;
	t_vector2	*hitpos;
	t_map		*map;
	t_vector2	player_pos;
	t_vector2	player_dir;
	t_vector2	plane;
	t_memory	*mem;
	t_texture	*textures;
	int			screen_width;
	t_vector2	mouse_pos;
}				t_display;

int		ft_maindisplay(t_cube *cube);
int		display_all(t_display *display);
int		display_screen(t_display *display);
void	fill_img(t_mlx_datas *datas, int color);
int		ft_message(char *line, int i);
int		ft_initdisplay(t_display **display, t_cube *cube);
void	ft_drawcf(t_display *display);
float	ft_decimal(float x);
void	ft_drawwalls(struct s_stripe stripe, t_display *display);
int		ft_opentextures(t_display *display, t_texture *textures);
void	ft_addshading(int *color, float dist);
void	ft_putblackimg(t_display *display);
void	ft_andrescircle(int xc, int yc, int r, t_display *display);
void	ft_andrescircleceiling(int xc, int yc, int r, t_display *display);
int		ft_getthird(char c, int color);
int		exit_cub(t_display *display);
void	ft_drawfloorshade(t_display *display);
void	ft_drawceilingshade(t_display *display);
void	ft_setcolourceiling(t_display *display);

#endif
