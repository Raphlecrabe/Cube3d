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
