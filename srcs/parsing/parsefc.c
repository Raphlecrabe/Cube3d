/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:04:43 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/27 14:04:16 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parsefloor(char *line, int i)
{
	if ((line[i + 1] < 9 || line[i + 1] > 13) && line[i + 1] != 32)
	{
		write(2, "Error, wrong texture format FLOOR\n", 35);
		return (-1);
	}
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (ft_isdigit(line[i]) != 1)
	{
		write(2, "Error, wrong texture format FLOOR\n", 35);
		return (-1);
	}
	return (0);
}

int	ft_parseceiling(char *line, int i)
{
	if ((line[i + 1] < 9 || line[i + 1] > 13) && line[i + 1] != 32)
	{
		write(2, "Error, wrong texture format CEILING\n", 37);
		return (-1);
	}
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (ft_isdigit(line[i]) != 1)
	{
		write(2, "Error, wrong texture format CEILING\n", 37);
		return (-1);
	}
	return (0);
}
