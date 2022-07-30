/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:40:15 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/28 11:18:51 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	main(int argc, char **argv)
{
	t_cube		*cube;
	t_memory	*mem;

	mem = NULL;
	(void)argc;
	cube = NULL;
	if (ft_initcube(&cube, mem) == -1)
	{
		ft_freemem(mem);
		return (-1);
	}
	if (ft_fullparse(cube, argv) == -1)
	{
		printf("lol\n");
		//ft_freemem(mem);
		return (-1);
	}
	//ft_printdoublechar(cube->map->lines);
	//ft_printtextures(cube);
}
