/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkholes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:04:24 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/22 15:29:19 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_checline_hole(char **lines, int i, int j)
{
	int	mem;

	mem = j;
	if (ft_isnumbers(lines[i][j]) == 1)
		return (0);
	while (lines[i][j] != '\0' && ft_isspace(lines[i][j]) == 1)
		j++;
	if (lines[i][j] == '\0')
		return (0);
	j = mem;
	while (j >= 0 && ft_isspace(lines[i][j]) == 1)
		j--;
	if (j == 0 && ft_isnumbers(lines[i][j]) == 0)
		return (0);
	return (1);
}

int	ft_checkcol_hole(char **lines, int i, int j)
{
	int	mem;

	mem = i;
	if (ft_isnumbers(lines[i][j]) == 1)
		return (0);
	while (lines[i] != NULL && ft_isspace(lines[i][j]) == 1)
		i++;
	if (lines[i] == NULL)
		return (0);
	i = mem;
	while (i >= 0 && ft_isspace(lines[i][j]) == 1)
		i--;
	if (i == 0 && ft_isnumbers(lines[i][j]) == 0)
		return (0);
	return (1);
}

int	ft_ishole(char **lines, int i, int j)
{
	if (ft_checkline_hole(lines, i, j) == 0)
		return (0);
	if (ft_checkcol_hole(lines, i, j) == 0)
		return (0);
}
