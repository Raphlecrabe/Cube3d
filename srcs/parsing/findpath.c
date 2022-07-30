/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:40:15 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/27 11:27:53 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_pathwest(t_cube *cube, char *line, int i)
{
	int	j;

	j = 0;
	while (line[i] != '\0'
		&& ((line[i] >= 9 && line[i] <= 13) || line[i] == 32))
		i = i + 1;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		j++;
		i++;
	}
	cube->west = ft_malloc_const(sizeof(char), (j + 1), cube->mem);
	if (cube->west == NULL)
		return (-1);
	cube->west[j] = '\0';
	i = i - j;
	j = 0;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		cube->west[j] = line[i];
		j++;
		i++;
	}
	cube->check.pwest = 1;
	return (0);
}

int	ft_patheast(t_cube *cube, char *line, int i)
{
	int	j;

	j = 0;
	while (line[i] != '\0'
		&& ((line[i] >= 9 && line[i] <= 13) || line[i] == 32))
		i = i + 1;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		j++;
		i++;
	}
	cube->east = ft_malloc_const(sizeof(char), (j + 1), cube->mem);
	if (cube->east == NULL)
		return (-1);
	cube->east[j] = '\0';
	i = i - j;
	j = 0;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		cube->east[j] = line[i];
		j++;
		i++;
	}
	cube->check.peast = 1;
	return (0);
}

int	ft_pathnorth(t_cube *cube, char *line, int i)
{
	int	j;

	j = 0;
	while (line[i] != '\0'
		&& ((line[i] >= 9 && line[i] <= 13) || line[i] == 32))
		i = i + 1;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		j++;
		i++;
	}
	cube->north = ft_malloc_const(sizeof(char), (j + 1), cube->mem);
	if (cube->north == NULL)
		return (-1);
	cube->north[j] = '\0';
	i = i - j;
	j = 0;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		cube->north[j] = line[i];
		j++;
		i++;
	}
	cube->check.pnorth = 1;
	return (0);
}

int	ft_pathsouth(t_cube *cube, char *line, int i)
{
	int	j;

	j = 0;
	while (line[i] != '\0'
		&& ((line[i] >= 9 && line[i] <= 13) || line[i] == 32))
		i = i + 1;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		j++;
		i++;
	}
	cube->south = ft_malloc_const(sizeof(char), (j + 1), cube->mem);
	if (cube->south == NULL)
		return (-1);
	cube->south[j] = '\0';
	i = i - j;
	j = 0;
	while (line[i] != '\0' && ((line[i] < 9 || line[i] > 13) && line[i] != 32))
	{
		cube->south[j] = line[i];
		j++;
		i++;
	}
	cube->check.psouth = 1;
	return (0);
}

int	ft_findpath(t_cube *cube, char *line, int i)
{
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i = i + 1;
	if (line[i] == 'W')
	{
		if (ft_pathwest(cube, line, i + 2) == -1)
			return (-1);
	}
	if (line[i] == 'E')
	{
		if (ft_patheast(cube, line, i + 2) == -1)
			return (-1);
	}
	if (line[i] == 'N')
	{
		if (ft_pathnorth(cube, line, i + 2) == -1)
			return (-1);
	}
	if (line[i] == 'S')
	{
		if (ft_pathsouth(cube, line, i + 2) == -1)
			return (-1);
	}
	return (0);
}
