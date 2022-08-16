/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/08/16 10:50:14 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include
#include "../incs/parsing.h"
#include "../incs/display.h"

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
}
