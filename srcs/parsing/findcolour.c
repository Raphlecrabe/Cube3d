/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcolour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:07 by rmonacho          #+#    #+#             */
/*   Updated: 2022/08/31 13:41:52 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_findf(t_cube *cube, char *line, int i)
{
	char	*colour;
	char	**numbers;

	if (cube->check.pfloor == 1)
		return (ft_message("Error, found a second same texture\n", -1));
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	colour = ft_getwhole(line, i, cube->mem);
	if (colour == NULL)
		return (-1);
	numbers = ft_split(colour, ',');
	if (numbers == NULL)
		return (-1);
	if (ft_testnumber(numbers) == -1)
		return (-1);
	cube->floor = ft_create_trgb(0, ft_atoi(numbers[0]),
			ft_atoi(numbers[1]), ft_atoi(numbers[2]));
	return (0);
}

int	ft_findc(t_cube *cube, char *line, int i)
{
	char	*colour;
	char	**numbers;

	if (cube->check.pceil == 1)
		return (ft_message("Error, found a second same texture\n", -1));
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	colour = ft_getwhole(line, i, cube->mem);
	if (colour == NULL)
		return (-1);
	numbers = ft_split_temp(colour, ',', cube->mem);
	if (numbers == NULL)
		return (-1);
	if (ft_testnumber(numbers) == -1)
		return (-1);
	cube->ceiling = ft_create_trgb(0, ft_atoi(numbers[0]),
			ft_atoi(numbers[1]), ft_atoi(numbers[2]));
	return (0);
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
		cube->check.pfloor = 1;
	}
	if (line[i] == 'C')
	{
		i++;
		if (ft_findc(cube, line, i) == -1)
			return (-1);
		cube->check.pceil = 1;
	}
	return (0);
}
