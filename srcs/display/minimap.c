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

static void	print_tile(t_mlx_datas *datas, t_vector2 point_ul, char tile)
{
	int			i;
	int			color;
	t_vector2	point_ur;

	i = 0;
	color = TILE_COLOR;
	if (tile != '1')
		color = BACKGROUND_COLOR;
	point_ur = vector2(point_ul.x + TILE_SIZE, point_ul.y);
	while (i < TILE_SIZE)
	{
		draw_line(datas, point_ul, point_ur, color);
		point_ul = vector2(point_ul.x, point_ul.y + 1);
		point_ur = vector2(point_ur.x, point_ur.y + 1);
		i++;
	}
}

static void	print_map(t_mlx_datas *datas, t_map *map)
{
	int			i;
	int			j;
	t_vector2	tile_coord;

	i = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j])
		{
			tile_coord = vector2(j * TILE_SIZE, i * TILE_SIZE);
			print_tile(datas, tile_coord, map->lines[i][j]);
			j++;
		}
		i++;
	}
}

static void	trace_raycast(t_mlx_datas *datas,
						t_vector2 player_pos, t_vector2 hitpos)
{
	t_vector2	player2screen;
	t_vector2	ray2screen;

	player2screen = vector2_multiply(player_pos, TILE_SIZE);
	ray2screen = vector2_multiply(hitpos, TILE_SIZE);
	draw_line(datas, player2screen, ray2screen, 0x00FF0000);
}

static void	print_raycasts(t_mlx_datas *datas, t_display *display)
{
	int		i;
	float	imax;
	float	factor;
	int		n;

	i = 0;
	imax = MINIMAP_RAY_NB;
	if (MINIMAP_RAY_NB > display->screen_width)
		imax = display->screen_width;
	factor = display->screen_width / (imax - 1);
	n = 0;
	if (imax == 1)
		n = display->screen_width / 2;
	while (i < (int)imax)
	{
		trace_raycast(datas, display->player_pos, display->hitpos[n]);
		n = (i + 1) * factor;
		if (i + 2 == imax)
			n--;
		i++;
	}
}

int	display_minimap(t_display *display)
{
	print_map(display->view, display->map);
	print_raycasts(display->view, display);
	return (1);
}
