/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:53:33 by rmonacho          #+#    #+#             */
/*   Updated: 2023/02/08 17:28:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

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
	cube->map->lines[cube->map->heigth] = NULL;
	while (mapmalloc)
	{
		ft_strlen((char *)mapmalloc->content);
		cube->map->lines[i] = ft_strncopy_const((char *)mapmalloc->content,
				cube->map->width + 1, ' ', cube->mem);
		if (cube->map->lines[i] == NULL)
			return (-1);
		cube->map->lines[i][cube->map->width] = '\0';
		i++;
		mapmalloc = mapmalloc->next;
	}
	return (0);
}

int	ft_initparsemap(t_cube *cube, char *line, int *j, t_list **mapping)
{
	*mapping = NULL;
	*j = 0;
	if (ft_islast(cube) == -1)
		return (-1);
	if (ft_parseline(cube, line, *j) == -1)
		return (-1);
	if (ft_addline(cube, line, mapping) == -1)
		return (-1);
	return (0);
}

int	ft_parsemap(t_cube *cube, char **line, int fd)
{
	t_list	*mapping;
	int		j;

	if (ft_initparsemap(cube, *line, &j, &mapping) == -1)
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
		return (ft_message("Error\nPlayer not found on the map\n", -1));
	cube->parsed = 1;
	return (0);
}
