/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:46:39 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/27 15:02:03 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_isempty(char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

int	ft_ismap(char *line, int i)
{
	i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (line[i] != '1' && line[i] != '0' && line[i] != '\n')
		return (0);
	return (1);
}

int	ft_testline(char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if ((line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'N' || line[i] == 'S') && ft_ismap(line, i) == 0)
		return (0);
	if (line[i] == 'F' || line[i] == 'C')
		return (0);
	if ((line[i] == '1' || line[i] == '0') || ((line[i] == 'W' || line[i] == 'E'
				|| line[i] == 'N' || line[i] == 'S')
			&& ft_ismap(line, i) == 1))
		return (2);
	if (ft_isempty(line) == 1)
		return (3);
	write(2, "Error, one line or more is not well configured\n", 40);
	return (-1);
}

int	ft_processline(t_cube *cube, char **line, int fd)
{
	int	i;

	i = ft_testline(*line);
	if (i == -1)
		return (-1);
	if (i == 0)
	{
		if (ft_addtexture(cube, *line) == -1)
			return (-1);
	}
	if (i == 2)
	{
		if (ft_parsemap(cube, line, fd) == -1)
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
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		if (ft_processline(cube, &line, fd) == -1)
		{
			free(line);
			return (-1);
		}
		if (cube->parsed == 0)
			free(line);
	}
	return (0);
}
