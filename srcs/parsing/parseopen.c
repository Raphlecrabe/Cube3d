/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseopen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:34:43 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/22 15:56:49 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_initparseonec(int j, char **lines, int *i)
{
	*i = 0;
	while (lines[*i] != NULL && ft_checkspacec(lines, j, *i) == 1)
			*i = *i + 1;
	if (line[*i][j] == '0')
		return (-1);
	while (lines[*i] != NULL && ft_checknumbersc(lines, j, *i) == 1)
		*i = *i + 1;
}

int	ft_parseonec(t_cube *cube, int j, char **lines)
{
	int	i;

	if (ft_initparseonec(j, lines, &i) == -1)
		return (-1);
	while (lines[i] != NULL)
	{
		while (lines[i] && ft_checkspacec(lines, j, i) == 1)
			i++;
		if (lines[i][j] == '0' || lines[i][j] == 'W'
			|| lines[i][j] == 'E' || lines[i][j] == 'N' || lines[i][j] == 'S')
			return (-1);
		while (lines[i] && ft_checknumbersc(lines, j, i))
			i++;
	}
	return (0);
}

int	ft_parsecolumns(t_cube *cube)
{
	int		j;

	j = 0;
	while (cube->map->lines[0][j] != '\0')
	{
		if (ft_parseonec(cube, j, cube->map->lines) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_parseopen(t_cube *cube)
{
	if (ft_parsecolumns(cube) == -1)
		return (ft_message("Error, map not closed\n", -1));
	if (ft_parselines(cube) == -1)
		return (ft_message("Error, map not closed\n", -1));
	return (0);
}
