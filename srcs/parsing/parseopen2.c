/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseopen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:50:27 by rmonacho          #+#    #+#             */
/*   Updated: 2022/08/31 17:37:54 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parseonel(char **lines, int i)
{
	int	j;

	j = 0;
	while (lines[i][j] != '\0')
	{
		while (lines[i][j] && ft_isspace(lines[i][j]) == 1)
			j++;
		if (lines[i][j] == '0' || lines[i][j] == 'W'
			|| lines[i][j] == 'E' || lines[i][j] == 'N' || lines[i][j] == 'S'
			|| lines[i][j] == '2' || lines[i][j] == '3' || lines[i][j] == '4')
			return (-1);
		while (lines[i][j] && ft_isnumbers(lines[i][j]) == 1)
			j++;
		if (lines[i][j - 1] == '0' || lines[i][j - 1] == 'W'
			|| lines[i][j - 1] == 'E'
			|| lines[i][j - 1] == 'N' || lines[i][j - 1] == 'S'
			|| lines[i][j - 1] == '2' || lines[i][j - 1] == '3'
			|| lines[i][j - 1] == '4')
			return (-1);
	}
	return (0);
}

int	ft_parselines(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->map->lines[i] != NULL)
	{
		if (ft_parseonel(cube->map->lines, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
