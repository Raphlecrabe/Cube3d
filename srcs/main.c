/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/08/04 12:59:38 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include
#include "../incs/parsing.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	if (argc != 2)
	{
		write(2, "Error, please use only one argument\n", 37);
		return (0);
	}
	if (ft_initcube(&cube) == -1)
		return (0);
	if (ft_fullparse(cube, argv) == -1)
		return (0);
	if (ft_maindisplay(cube) == -1)
		return (0);
	
	
	//la suite plus tard
}
