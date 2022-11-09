/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:26:40 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/09 13:08:54 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_openmap(char **argv)
{
	int		i;
	char	line[1];

	i = open(argv[1], O_RDONLY);
	if (i < 0)
		return (ft_message("Error\nCan't open map\n", -1));
	if (read(i, line, 1) < 0)
		return (ft_message("Error\nCan't open map\n", -1));
	close(i);
	i = open(argv[1], O_RDONLY);
	if (i < 0)
		return (ft_message("Error\nCan't open map\n", -1));
	return (i);
}
