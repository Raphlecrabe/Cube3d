/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/09/08 12:13:32 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

//include
#include "../incs/parsing.h"
#include "../incs/display.h"
#include <limits.h>

int	exit_cub(t_display *display)
{
	if (display)
	{
		if (display->mlx && display->view->img);
			mlx_destroy_image(display->mlx, display->view->img);
		if (display->mlx && display->mlx_win)
			mlx_destroy_window(display->mlx, display->mlx_win);
		ft_freemem(display->mem);
		free(display->mem);
	}
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
	{
		if (ft_fullparse(cube, argv) != -1)
		{
			if (cube->parsed == 0)
				return (ft_message("Error, map is not complete\n", -1));
			ft_maindisplay(cube);
		}
	}
	ft_freemem(mem);
	free(mem);
}
