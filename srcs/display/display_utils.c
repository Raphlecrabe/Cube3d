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

int	img_clean(void *mlx, t_mlx_datas *datas)
{
	if (datas->img != NULL)
		mlx_destroy_image(mlx, datas->img);
	datas->img = mlx_new_image(mlx, datas->img_size.x, datas->img_size.y);
	if (datas->img == NULL)
		return (0);
	datas->addr = mlx_get_data_addr(datas->img, &datas->bits_per_pixel,
			&datas->line_length, &datas->endian);
	return (1);
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
