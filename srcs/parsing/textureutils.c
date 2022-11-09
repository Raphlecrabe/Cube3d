/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:15:54 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/09 13:10:33 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_parsewest(char *line, int i)
{
	if (line[i + 1] != 'E')
	{
		ft_putstr_fd("Error\nWrong texture format : WE\n", 2);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		ft_putstr_fd("Error\nWrong texture format : WE\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_parseeast(char *line, int i)
{
	if (line[i + 1] != 'A')
	{
		ft_putstr_fd("Error\nWrong texture format : EA\n", 2);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		ft_putstr_fd("Error\nWrong texture format : EA\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_parsenorth(char *line, int i)
{
	if (line[i + 1] != 'O')
	{
		ft_putstr_fd("Error\nWrong texture format : NO\n", 2);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		ft_putstr_fd("Error\nWrong texture format : NO\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_parsesouth(char *line, int i)
{
	if (line[i + 1] != 'O')
	{
		ft_putstr_fd("Error\nWrong texture format : SO\n", 2);
		return (-1);
	}
	if ((line[i + 2] < 9 || line[i + 2] > 13) && line[i + 2] != 32)
	{
		ft_putstr_fd("Error\nWrong texture format : SO\n", 2);
		return (-1);
	}
	return (0);
}
