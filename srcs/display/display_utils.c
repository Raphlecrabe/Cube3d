/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:09:07 by marvin            #+#    #+#             */
/*   Updated: 2022/07/29 12:09:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/mlx_utils.h"
#include "../../incs/vectors.h"
#include <mlx.h>
#include <stdio.h>

void	ft_drawcf(t_display *display)
{
	int	i;
	int	j;
	int	middle;

	i = 0;
	j = 0;
	middle = (int)display->win_size.y / 2 + (int)display->win_size.y % 2;
	while (i < display->win_size.x - 1)
	{
		while (j < middle - 1)
		{
			my_mlx_pixel_put(display->view, i, j, display->textures->ceiling);
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
	j = middle;
	while (i < display->win_size.x - 1)
	{
		while (j < display->win_size.y - 1)
		{
			my_mlx_pixel_put(display->view, i, j, display->textures->floor);
			j++;
		}
		i++;
		j = middle;
	}
}

void	img_clean(void *mlx, t_mlx_datas *datas)
{
	mlx_destroy_image(mlx, datas->img);
	datas->img = mlx_new_image(mlx, datas->img_size.x, datas->img_size.y);
	datas->addr = mlx_get_data_addr(datas->img, &datas->bits_per_pixel,
			&datas->line_length, &datas->endian);
}

void	fill_img(t_mlx_datas *datas, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < datas->img_size.y)
	{
		x = 0;
		while (x < datas->img_size.x)
		{
			my_mlx_pixel_put(datas, x, y, color);
			x++;
		}
		y++;
	}
}
