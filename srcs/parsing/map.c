/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:33 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/19 11:49:24 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parsemap(t_cube *cube, char *line, int fd)
{
	if (ft_islast(cube) == -1)
		return (-1);
	if (ft_parseline(cube, line) == -1)
		return (-1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		if (ft_parseline(cube, line) == -1)
			return (-1);
		if (ft_addline(cube, line) == -1)
			return (-1);
	}
	ft_parseopen(cube, line);
}
