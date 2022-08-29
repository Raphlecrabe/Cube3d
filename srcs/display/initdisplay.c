/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdisplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:58:20 by rafy              #+#    #+#             */
/*   Updated: 2022/08/29 13:51:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

int	ft_initdisplay(t_display **display, t_cube *cube)
{
	*display = ft_malloc_const(sizeof(t_display), 1, cube->mem);
	if (*display == NULL)
		return (-1);
	(*display)->map = cube->map;
	(*display)->player_pos = cube->playerinit->coord;
	(*display)->player_dir = cube->playerinit->angle;
	(*display)->mem = cube->mem;

	(*display)->textures = ft_malloc_const(sizeof(t_texture), 1, cube->mem);
	if ((*display)->textures == NULL)
		return (-1);
	(*display)->textures->west = cube->west;
	(*display)->textures->east = cube->east;
	(*display)->textures->north = cube->north;
	(*display)->textures->south = cube->south;
	(*display)->textures->ceiling = cube->ceiling;
	(*display)->textures->floor = cube->floor;


	(*display)->plane = vector2(0.66f, 0);
	(*display)->screen_width = 800;
	(*display)->win_size = vector2(800, 800);
	(*display)->mousePos = vector2((*display)->screen_width / 2, 0);

	(*display)->mlx = mlx_init();
	(*display)->view = ft_malloc_temp(sizeof(t_mlx_datas), 1, (*display)->mem);
	if ((*display)->view == NULL)
		return (-1);
	init_mlxdatas((*display)->mlx, (*display)->win_size, (*display)->view);
	
	(*display)->minimap = (*display)->view;
	// (*display)->minimap = ft_malloc_temp(sizeof(t_mlx_datas),
	// 		1, (*display)->mem);
	// if ((*display)->minimap == NULL)
	// 	return (-1);
	//init_mlxdatas((*display)->mlx, minimap_size(cube->map), (*display)->minimap);
	(*display)->mlx_win = mlx_new_window((*display)->mlx,
			(*display)->win_size.x, (*display)->win_size.y, "cub3d");
	return (0);

	(*display)->z_buffer = ft_malloc_const(sizeof(int), (*display)->screen_width, (*display)->mem);
}
