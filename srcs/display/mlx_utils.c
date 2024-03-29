/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:31:10 by marvin            #+#    #+#             */
/*   Updated: 2022/07/22 14:31:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include <math.h>

void	ft_setcolourceiling(t_display *display)
{
	if (SHADE != 1)
		display->textures->shade = display->textures->ceiling;
	else
	{
		display->textures->shade = create_trgb(0,
				((display->textures->ceiling >> 16) & 0xFF)
				* 0.2,
				((display->textures->ceiling >> 8) & 0xFF)
				* 0.2,
				(display->textures->ceiling & 0xFF)
				* 0.2);
	}
}

int	init_mlxdatas(void *mlx, t_vector2 img_size, t_mlx_datas *datas)
{
	mlx += 0;
	(*datas).img_size = img_size;
	(*datas).img = mlx_new_image(mlx, datas->img_size.x, datas->img_size.y);
	if (datas->img == NULL)
	{
		return (-1);
	}
	datas->addr = mlx_get_data_addr(datas->img, &datas->bits_per_pixel,
			&datas->line_length, &datas->endian);
	datas->bits_per_pix_calculated = datas->bits_per_pixel / 8;
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx_datas *datas, int x, int y, int color)
{
	char	*dst;

	dst = datas->addr + (y * datas->line_length
			+ x * (datas->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_mlx_datas *datas,
				t_vector2 point_from, t_vector2 point_to, int color)
{
	t_vector2	diff;
	t_vector2	new_point;
	int			max;
	int			i;

	i = 0;
	diff = vector2_substract(point_to, point_from);
	max = fmax(fabs(diff.x), fabs(diff.y));
	new_point = vector2((int)point_from.x, (int)point_from.y);
	while (i <= max)
	{
		if (new_point.x >= 0 && new_point.x < datas->img_size.x
			&& new_point.y >= 0 && new_point.y < datas->img_size.y)
			my_mlx_pixel_put(datas, new_point.x, new_point.y, color);
		new_point.x = (int)(point_from.x + (diff.x * i) / max);
		new_point.y = (int)(point_from.y + (diff.y * i) / max);
		i++;
	}
}
