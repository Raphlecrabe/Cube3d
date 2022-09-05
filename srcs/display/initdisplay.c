/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdisplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:58:20 by rafy              #+#    #+#             */
/*   Updated: 2022/08/31 18:30:52 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

int	ft_init_textures(t_display **display, t_cube *cube)
{
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

int	ft_init_map(t_display **display, t_cube *cube)
{
	*display = ft_malloc_const(sizeof(t_display), 1, cube->mem);
	if (*display == NULL)
		return (-1);
	(*display)->map = cube->map;
	(*display)->player_pos = cube->playerinit->coord;
	(*display)->player_dir = cube->playerinit->angle;
	(*display)->mem = cube->mem;
	return (0);
}

int	ft_initdisplay(t_display **display, t_cube *cube)
{
	if (ft_init_map(display, cube) == -1)
		return (-1);
	if (ft_init_textures(display, cube) == -1)
		return (-1);
	(*display)->plane = vector2(0.66f, 0);
	(*display)->screen_width = 1900;
	(*display)->win_size = vector2(1900, 1080);
	(*display)->mlx = mlx_init();
	(*display)->view = ft_malloc_temp(sizeof(t_mlx_datas), 1, (*display)->mem);
	if ((*display)->view == NULL)
		return (-1);
	init_mlxdatas((*display)->mlx, (*display)->win_size, (*display)->view);
	(*display)->minimap = ft_malloc_temp(sizeof(t_mlx_datas),
			1, (*display)->mem);
	if ((*display)->minimap == NULL)
		return (-1);
	init_mlxdatas((*display)->mlx, vector2(300, 300), (*display)->minimap);
	(*display)->mlx_win = mlx_new_window((*display)->mlx,
			(*display)->win_size.x, (*display)->win_size.y, "cub3d");
	return (0);
}
