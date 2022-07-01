/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:46:39 by rmonacho          #+#    #+#             */
/*   Updated: 2022/06/30 14:07:15 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_testline(char **line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'N' || line[i] == 'S')
		return (0);
	if (line[i] == 'F' || line[i] == 'C')
		return (1);
	if (line[i] == '1' || line[i] == '0')
		return (2);
	return (3);
}

int	ft_processline(t_cube *cube, char *line)
{
	int	i;

	i = ft_testline(line);
	if (i == -1)
		return (-1);
	if (i == 0)
	{
		if (ft_addtexture(cube, line) == -1)
			return (-1);
	}
	if (i == 1)
	{
		if (ft_addfloorceiling(cube, line) == -1)
			return (-1);
	}
	if (i == 2)
	{
		if (ft_parsemap(cube, line) == -1)
			return (-1);
		cube->parsed = 1;
	}
	return (0);
}

int	ft_fullparse(t_cube *cube, char **argv)
{
	char	*line;
	int		fd;

	fd = ft_openmap(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		if (ft_processline(cube, line) == -1)
			return (-1);
	}
	return (0);
}
