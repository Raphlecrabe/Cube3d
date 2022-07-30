#ifndef MLX_UTILS_H
# define MLX_UTILS_H

#include "vectors.h"

typedef struct	s_mlx_datas{
	void		*img;
	char		*addr;
	t_vector2	img_size;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_datas;	

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_mlx_datas *datas, int x, int y, int color);
void	draw_line(t_mlx_datas *datas, t_vector2 point_from, t_vector2 point_to, int color);

#endif