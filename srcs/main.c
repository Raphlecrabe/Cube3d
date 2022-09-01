/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/08/30 11:32:11 by rafy             ###   ########.fr       */
=======
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 6e71e016ad5d89327d08f12d8e4543bf069dfbc4
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
	mem = malloc(sizeof(t_memory) * 1);
	if (mem == NULL)
		return (0);
	mem->used = NULL;
	if (ft_initcube(&cube, mem) != -1)
		if (ft_fullparse(cube, argv) != -1)
			ft_maindisplay(cube);
	ft_freemem(mem);
	free(mem);
	//free le t memory et le garbage
	//détruire les img des textures
	//détruire l'img de l'affichage + minimap
	//détruire la window + mlx
}
