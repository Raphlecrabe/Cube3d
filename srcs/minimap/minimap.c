/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:28:04 by marvin            #+#    #+#             */
/*   Updated: 2022/07/27 15:28:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minimap.h"
#include "../../incs/mlx_utils.h"
#include <mlx.h>
#include <stdio.h>

static void print_tile(t_mlx_datas *datas, t_vector2 point_ul, char tile)
{
	int	i;
	int color;
	t_vector2 point_ur;
	t_vector2 point_bl;
	t_vector2 point_br;

	i = 0;
	color = 0x00FF0000;
	point_ur = vector2(point_ul.x + TILE_SIZE - 1, point_ul.y);
	point_bl = vector2(point_ul.x, point_ul.y + TILE_SIZE - 1);
	point_br = vector2(point_ul.x + TILE_SIZE - 1, point_ul.y + TILE_SIZE - 1);
	draw_line(datas, point_ul, point_ur, color);
	draw_line(datas, point_ul, point_bl, color);
	draw_line(datas, point_ur, point_br, color);
	draw_line(datas, point_bl, point_br, color);

	if (tile != '0')
	{
		while (i + 2 < TILE_SIZE)
		{
			point_ul = vector2(point_ul.x, point_ul.y + 1);
			point_ur = vector2(point_ur.x, point_ur.y + 1);
			draw_line(datas, point_ul, point_ur, color);
			i++;
		}
	}
}

static void print_map(t_mlx_datas *datas, t_map *map)
{
	t_vector2 tile_coord;
	int	i;
	int	j;

	i = 0;
	while (map->lines[i] && i < 24)
	{
		j = 0;
		while (map->lines[i][j] && j < 24)
		{
			tile_coord = vector2(i * TILE_SIZE, j * TILE_SIZE);
			print_tile(datas, tile_coord, map->lines[i][j]);
			j++;
		}
		i++;
	}
}

void minimap_display(t_display *display)
{
	print_map(display->datas, display->map);

	mlx_put_image_to_window(display->mlx, display->mlx_win, display->datas->img, 0, 0);

	printf("image put to window\n");
}