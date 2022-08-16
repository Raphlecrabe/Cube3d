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
# include <mlx.h>
# include <stdio.h>

typedef struct s_texture
{
	char	*west;
	char	*east;
	char	*north;
	char	*south;
	int		ceiling;
	int		floor;
}	t_texture;

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

}		t_display;

int			display_screen(t_display *display);
void		img_clean(void *mlx, t_mlx_datas *datas);
void		fill_img(t_mlx_datas *datas, int color);
void		ft_drawcf(t_display *display);
int			ft_initdisplay(t_display **display, t_cube *cube);
t_mlx_datas	init_mlxdatas(void *mlx, t_vector2 img_size);
int			ft_maindisplay(t_cube *cube);

# include "raycast.h"
# include "minimap.h"

#endif