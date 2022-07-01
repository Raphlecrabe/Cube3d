/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcoulour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:07 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/01 15:31:16 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_findf(t_cube *cube, char *line, int i)
{
	char	*colour;
	char	**numbers;

	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	colour = ft_getwhole(line, i);
	if (colour == NULL)
		return (-1);
	numbers = ft_split(colour, ',');
	if (numbers == NULL)
		return (-1);
	if (ft_testnumber(numbers) == -1)
		return (-1);
	cube->floor.r = ft_atoi(numbers[0]);
	cube->floor.g = ft_atoi(numbers[1]);
	cube->floor.b = ft_atoi(numbers[2]);
}

int	ft_findc(t_cube *cube, char *line, int i)
{
	char	*colour;
	char	**numbers;

	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	colour = ft_getwhole(line, i);
	if (colour == NULL)
		return (-1);
	numbers = ft_split(colour, ',');
	if (numbers == NULL)
		return (-1);
	if (ft_testnumber(numbers) == -1)
		return (-1);
	cube->ceiling.r = ft_atoi(numbers[0]);
	cube->ceiling.g = ft_atoi(numbers[1]);
	cube->ceiling.b = ft_atoi(numbers[2]);
}

int	ft_findcolour(t_cube *cube, char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	if (line[i] == 'F')
	{
		i++;
		if (ft_findf(cube, line, i) == -1)
			return (-1);
	}
	if (line[i] == 'C')
	{
		i++;
		if (ft_findc(cube, line, i) == -1)
			return (-1);
	}
}
