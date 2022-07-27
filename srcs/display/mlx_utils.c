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

#include "../../incs/mlx_utils.h"
#include "../../incs/vectors.h"
#include <math.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx_datas *datas, int x, int y, int color)
{
	char	*dst;

	dst = datas->addr + (y * datas->line_length + x * (datas->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_mlx_datas *datas, t_vector2 point_from, t_vector2 point_to, int color)
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
		if (new_point.x >= 0 && new_point.x < datas->win_size.x
			&& new_point.y >= 0 && new_point.y < datas->win_size.y)
			my_mlx_pixel_put(datas, new_point.x, new_point.y, color);
		new_point.x = (int) (point_from.x + (diff.x * i) / max);
		new_point.y = (int) (point_from.y + (diff.y * i) / max);
		i++;
	}
}
