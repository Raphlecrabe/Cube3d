/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:45 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/01 14:37:42 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parsefc(char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	if (line[i] == 'F')
	{
		if (ft_parsefloor(line, i) == -1)
			return (-1);
	}
	if (line[i] == 'C')
	{
		if (ft_parseceiling(line, i) == -1)
			return (-1);
	}
	return (0);
}

int	ft_parsetexture(t_cube *cube, char *line, int i)
{
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	if (line[i] == 'W')
	{
		if (ft_parsewest(cube, line, i) == -1)
			return (-1);
	}
	if (line[i] == 'E')
	{
		if (ft_parseeast(cube, line, i) == -1)
			return (-1);
	}
	if (line[i] == 'N')
	{
		if (ft_parsenorth(cube, line, i) == -1)
			return (-1);
	}
	if (line[i] == 'S')
	{
		if (ft_parsesouth(cube, line, i) == -1)
			return (-1);
	}
	return (0);
}

int	ft_addtexture(t_cube *cube, char *line)
{
	int	i;

	i = 0;
	if (ft_parsetexture(cube, line, i) == -1)
		return (-1);
	if (ft_parsefc(line) == -1)
		return (-1);
	if (ft_findpath(cube, line, i) == -1)
		return (-1);
	if (ft_findcolour(cube, line) == -1)
		return (-1);
}
