/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2023/02/08 18:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

//include
#include "../incs/parsing.h"
#include "../incs/display.h"
#include <limits.h>

int	mapformat(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len >= 4 && ft_strncmp(".cub", &map[len - 4], 4) == 0)
		return (0);
	ft_putstr_fd("Error\nWrong map format\n", 2);
	return (-1);
}

int	exit_cub(t_display *display)
{
	if (display)
	{
		mlx_destroy_image(display->mlx, display->textures->wtext->img);
		mlx_destroy_image(display->mlx, display->textures->etext->img);
		mlx_destroy_image(display->mlx, display->textures->ntext->img);
		mlx_destroy_image(display->mlx, display->textures->stext->img);
		if (display->mlx && display->view->img)
			mlx_destroy_image(display->mlx, display->view->img);
		if (display->mlx && display->mlx_win)
			mlx_destroy_window(display->mlx, display->mlx_win);
		void *mem = display->mem;
		ft_freemem(display->mem);
		free(mem);
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cube		*cube;
	t_memory	*mem;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nPlease use only one argument\n", 2);
		return (0);
	}
	if (mapformat(argv[1]) == -1)
		return (0);
	mem = malloc(sizeof(t_memory) * 1);
	if (mem == NULL)
		return (0);
	mem->used = NULL;
	if (ft_initcube(&cube, mem) != -1)
	{
		if (ft_fullparse(cube, argv) != -1)
		{
			if (cube->parsed == 0)
				return (ft_message("Error\nMap is not complete\n", -1));
			ft_maindisplay(cube);
		}
	}
	ft_freemem(mem);
	free(mem);
}
