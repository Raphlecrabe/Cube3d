/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:15:54 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/01 14:38:27 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parsewest(t_cube *cube, char *line, int i)
{
	if (line[i + 1] != 'E')
	{
		write(2, "Error, wrong texture format : WE\n", 34);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		write(2, "Error, wrong texture format : WE\n", 34);
		return (-1);
	}
}

int	ft_parseeast(t_cube *cube, char *line, int i)
{
	if (line[i + 1] != 'A')
	{
		write(2, "Error, wrong texture format : EA\n", 34);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		write(2, "Error, wrong texture format : EA\n", 34);
		return (-1);
	}
}

int	ft_parsenorth(t_cube *cube, char *line, int i)
{
	if (line[i + 1] != 'O')
	{
		write(2, "Error, wrong texture format : NO\n", 34);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		write(2, "Error, wrong texture format : NO\n", 34);
		return (-1);
	}
}

int	ft_parsesouth(t_cube *cube, char *line, int i)
{
	if (line[i + 1] != 'O')
	{
		write(2, "Error, wrong texture format : SO\n", 34);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		write(2, "Error, wrong texture format : SO\n", 34);
		return (-1);
	}
}
