/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdisplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:58:20 by rafy              #+#    #+#             */
/*   Updated: 2022/08/15 17:03:35 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

int	ft_initdisplay(t_display **display, t_cube *cube)
{
	t_mlx_datas	datas;

	*display = ft_malloc_const(sizeof(t_display), 1, cube->mem);
	if (*display == NULL)
		return (-1);
	(*display)->map = cube->map;
	(*display)->player_pos = cube->playerinit->coord;
	(*display)->player_dir = cube->playerinit->angle;
	(*display)->plane = vector2(0.66f, 0);
	(*display)->screen_width = 50;
	(*display)->win_size = vector2(800, 800);
	(*display)->mem = cube->mem;
	(*display)->mlx = mlx_init();
	datas = init_mlxdatas((*display)->mlx, (*display)->win_size);
	(*display)->view = &datas;
	datas = init_mlxdatas((*display)->mlx, vector2(300, 300));
	(*display)->minimap = &datas;
	(*display)->mlx_win = mlx_new_window((*display)->mlx,
			(*display)->win_size.x, (*display)->win_size.y, "cub3d");
	(*display)->textures = ft_malloc_const(sizeof(t_texture), 1, cube->mem);
	if ((*display)->textures == NULL)
		return (-1);
	(*display)->textures->west = cube->west;
	(*display)->textures->east = cube->east;
	(*display)->textures->north = cube->north;
	(*display)->textures->south = cube->south;
	(*display)->textures->ceiling = cube->ceiling;
	(*display)->textures->floor = cube->floor;
	return (0);
}
