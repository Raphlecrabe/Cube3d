/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/09/01 14:03:54 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include
#include "../incs/parsing.h"
#include "../incs/display.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	t_cube		*cube;
	t_memory	*mem;

	if (argc != 2)
	{
		write(2, "Error, please use only one argument\n", 37);
		return (0);
	}
	mem = NULL;
	if (ft_initcube(&cube, mem) == -1)
		return (0);
	if (ft_fullparse(cube, argv) == -1)
		return (0);
	if (ft_maindisplay(cube) == -1)
		return (0);
	//free le t memory et le garbage
	//détruire les img des textures
	//détruire l'img de l'affichage + minimap
	//détruire la window + mlx
}
