#ifndef DISPLAY_H
# define DISPLAY_H

#include "cube3d.h"
#include "vectors.h"
#include "garbage.h"
#include "mlx_utils.h"

typedef struct s_texture
{
	char	*west;
	char	*east;
	char	*north;
	char	*south;
	int		ceiling;
	int		floor;
}

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

}				t_display;

int		display_screen(t_display *display);
void	img_clean(void *mlx, t_mlx_datas *datas);
void 	fill_img(t_mlx_datas *datas, int color);

#endif