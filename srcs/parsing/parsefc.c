/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:04:43 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/09 13:09:12 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parsefloor(char *line, int i)
{
	if ((line[i + 1] < 9 || line[i + 1] > 13) && line[i + 1] != 32)
	{
		ft_putstr_fd("Error\nWrong texture format FLOOR\n", 2);
		return (-1);
	}
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (ft_isdigit(line[i]) != 1)
	{
		ft_putstr_fd("Error\nWrong texture format FLOOR\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_parseceiling(char *line, int i)
{
	if ((line[i + 1] < 9 || line[i + 1] > 13) && line[i + 1] != 32)
	{
		ft_putstr_fd("Error\nWrong texture format CEILING\n", 2);
		return (-1);
	}
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (ft_isdigit(line[i]) != 1)
	{
		ft_putstr_fd("Error\nWrong texture format CEILING\n", 2);
		return (-1);
	}
	return (0);
}
