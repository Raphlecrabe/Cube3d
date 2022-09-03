/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/09/03 11:08:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

//include
#include "../incs/parsing.h"
#include "../incs/display.h"
#include <limits.h>

void	exit_cub(t_display *display)
{
	mlx_destroy_image(display->mlx, display->view->img);
	mlx_destroy_window(display->mlx, display->mlx_win);
	ft_freemem(display->mem);
	free(display->mem);
	//free le t memory et le garbage
	//détruire les img des textures
	//détruire l'img de l'affichage + minimap
	//détruire la window + mlx
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cube		*cube;
	t_memory	*mem;

	if (argc != 2)
	{
		write(2, "Error, please use only one argument\n", 37);
		return (0);
	}
	mem = malloc(sizeof(t_memory) * 1);
	if (mem == NULL)
		return (0);
	mem->used = NULL;
	if (ft_initcube(&cube, mem) != -1)
		if (ft_fullparse(cube, argv) != -1)
			ft_maindisplay(cube);
	ft_freemem(mem);
	free(mem);
}
