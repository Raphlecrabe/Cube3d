/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:33:49 by raphael           #+#    #+#             */
/*   Updated: 2022/07/28 14:09:35 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_islast(t_cube *cube)
{
	if (cube->check.pfloor != 1 || cube->check.pceil != 1
		|| cube->check.pwest != 1 || cube->check.peast != 1
		|| cube->check.psouth != 1 || cube->check.pnorth != 1)
	{
		write(2, "Error, map is not last or wrong format on textures\n", 51);
		return (-1);
	}
	return (0);
}

int	ft_parseline(t_cube *cube, char *l)
{
	int	i;

	i = 0;
	while (l[i] != '\0')
	{
		while (l[i] != '\0' && l[i] != '\n'
			&& ((l[i] >= 9 && l[i] <= 13) || l[i] == 32))
			i = i + 1;
		if (l[i] == 'W' || l[i] == 'E' || l[i] == 'N' || l[i] == 'S')
		{
			if (cube->check.player == 1)
			{
				write(2, "Error, second player found on the map\n", 38);
				return (-1);
			}
			cube->check.player = 1;
		}
		if (l[i] != '0' && l[i] != '1' && l[i] != 'W'
			&& l[i] != 'E' && l[i] != 'S' && l[i] != 'N' && l[i] != '\n'
			&& l[i] != '\0')
			return (ft_message("Error, wrong format map\n", -1));
		i++;
	}
	return (0);
}

int	ft_addline(t_cube *cube, char *line, t_list **mapping)
{
	t_list	*lista;
	char	*temp;

	temp = ft_strdup_temp(line, cube->mem);
	lista = ft_lstnew_temp(temp, cube->mem);
	if (lista == NULL)
		return (-1);
	ft_lstadd_back(mapping, lista);
	return (0);
}
