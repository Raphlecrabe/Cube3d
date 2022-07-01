/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:23:36 by rmonacho          #+#    #+#             */
/*   Updated: 2022/06/30 13:39:53 by rmonacho         ###   ########lyon.fr   */
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
	if (ft_initstruct(&cube) == -1)
		return (0);
	if (ft_parsefull(argv) == -1)
		return (0);
	//la suite plus tard
}
