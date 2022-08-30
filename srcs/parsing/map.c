/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:33 by rmonacho          #+#    #+#             */
/*   Updated: 2022/08/16 10:51:36 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

/*void	ft_miniholes(char **lines, int *i, int *j)
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

void	ft_convertholes(char **lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lines[i] != NULL)
	{
		j = 0;
		ft_miniholes(lines, &i, &j);
		i++;
	}
}*/

size_t	ft_maxlines(t_list *mapping)
{
	size_t	i;

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
	t_list	*mapmalloc;

	i = 0;
	mapmalloc = mapping;
	cube->map = ft_malloc_const(sizeof(t_map), 1, cube->mem);
	if (cube->map == NULL)
		return (-1);
	cube->map->heigth = ft_lstsize(mapping);
	cube->map->width = ft_maxlines(mapping);
	cube->map->lines = ft_malloc_const(sizeof(char *),
			(cube->map->heigth + 1), cube->mem);
	if (cube->map->lines == NULL)
		return (-1);
	while (mapmalloc)
	{
		ft_strlen((char *)mapmalloc->content);
		cube->map->lines[i] = ft_strncopy_const((char *)mapmalloc->content,
				cube->map->width, ' ', cube->mem);
		if (cube->map->lines[i] == NULL)
			return (-1);
		i++;
		mapmalloc = mapmalloc->next;
	}
	return (0);
}

int	ft_parsemap(t_cube *cube, char **line, int fd)
{
	t_list	*mapping;
	int		j;

	mapping = NULL;
	j = 0;
	if (ft_islast(cube) == -1)
		return (-1);
	if (ft_parseline(cube, *line, j) == -1)
		return (-1);
	if (ft_addline(cube, *line, &mapping) == -1)
		return (-1);
	while (*line != NULL)
	{
		free(*line);
		j++;
		*line = get_next_line(fd);
		if (*line == NULL)
			break ;
		if (ft_parseline(cube, *line, j) == -1)
			return (-1);
		if (ft_addline(cube, *line, &mapping) == -1)
			return (-1);
	}
	if (ft_convertchar(cube, mapping) == -1)
		return (-1);
	if (ft_parseopen(cube) == -1)
		return (-1);
	if (cube->check.player != 1)
		return (ft_message("Error, player not found on the map\n", -1));
	cube->parsed = 1;
	return (0);
}
