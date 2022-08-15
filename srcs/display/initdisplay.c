/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdisplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:58:20 by rafy              #+#    #+#             */
/*   Updated: 2022/08/05 17:38:35 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/mlx_utils.h"
#include <mlx.h>

int	ft_initdisplay(t_display **display, t_cube *cube)
{
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
	(*display)->view = &init_mlxdatas((*display)->mlx, (*display)->win_size);
	(*display)->minimap = &init_mlxdatas((*display)->mlx, vector2(300, 300));
	(*display)->mlx_win = mlx_new_window((*display)->mlx,
			(*display)->win_size.x, (*display)->win_size.y, "cub3d");
	return (0);
}
