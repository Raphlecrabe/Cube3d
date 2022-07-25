/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:33 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/22 15:02:19 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

void	ft_miniholes(char **lines, int *i, int *j)
{
	while (lines[*i][*j] != '\0' && ft_isspace(lines[*i][*j]) == 1)
			*j = *j + 1;
	while (lines[*i][*j] != '\0')
	{
		while (lines[*i][*j] != '\0' && ft_isnumbers(lines[*i][*j]) == 1)
			*j = *j + 1;
		if (ft_ishole(lines, *i, *j) == 1)
		{
			lines[*i][*j] = '0';
			*j = *j + 1;
		}
		else
		{
			while (lines[*i][*j] != '\0' && ft_isspace(lines[*i][*j]) == 1)
				*j = *j + 1;
		}
	}
}

void	ft_convertholes(t_cube *cube, char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lines[i] != NULL)
	{
		ft_miniholes(lines, &i, &j);
	}
}

int	ft_maxlines(t_list *mapping)
{
	int	i;

	i = 0;
	while (mapping)
	{
		if (i <= ft_strlen((char *)mapping->content))
			i = ft_strlen((char *)mapping->content);
		mapping = mapping->next;
	}
	return (i);
}

int	ft_convertchar(t_cube *cube, t_list *mapping)
{
	int		i;
	int		j;
	t_list	*mapmalloc;

	i = 0;
	j = 0;
	mapmalloc = mapping;
	cube->map->heigth = ft_lstsize(mapping);
	cube->map->width = ft_maxlines(mapping);
	cube->map->lines = ft_malloc_const(sizeof(char *),
			(cube->map->heigth + 1), cube->mem);
	if (cube->map->lines == NULL)
		return (-1);
	while (mapmalloc)
	{
		j = ft_strlen((char *)mapmalloc->content);
		cube->map->lines[i] = ft_strncopy_const((char *)mapmalloc->content,
				cube->map->width, ' ', cube->mem);
		if (cube->map->lines[i] == NULL)
			return (-1);
		i++;
		mapmalloc = mapmalloc->next;
	}
	return (0);
}

int	ft_parsemap(t_cube *cube, char *line, int fd)
{
	t_list	*mapping;

	if (ft_islast(cube) == -1)
		return (-1);
	if (ft_parseline(cube, line) == -1)
		return (-1);
	if (ft_addline(cube, line, mapping) == -1)
		return (-1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		if (ft_parseline(cube, line) == -1)
			return (-1);
		if (ft_addline(cube, line, mapping) == -1)
			return (-1);
	}
	if (ft_convertchar(cube, mapping) == -1)
		return (-1);
	ft_convertholes(cube, cube->map->lines);
	if (ft_parseopen(cube) == -1)
		return (-1);
}
