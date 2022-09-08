/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openspritewall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:49:42 by raphael           #+#    #+#             */
/*   Updated: 2022/09/06 13:26:22 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

int	ft_parsepng(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] == 'g' && path[i - 2] == 'n'
		&& path[i - 3] == 'p' && path[i - 4] == '.')
		return (1);
	if (path[i - 1] == 'm' && path[i - 2] == 'p'
		&& path[i - 3] == 'x' && path[i - 4] == '.')
		return (0);
	return (ft_message("Error, wrong format texture\n", -1));
}

int	ft_open_one_text(t_display *display, char *path, t_mlx_datas **imgpoint)
{
	int	i;
	int	sizes[2];

	i = ft_parsepng(path);
	if (i == -1)
		return (-1);
	*imgpoint = ft_malloc_const(sizeof(t_mlx_datas), 1, display->mem);
	if (*imgpoint == NULL)
		return (-1);
	if (i == 0)
	{
		(*imgpoint)->img = mlx_xpm_file_to_image(display->mlx,
				path, &sizes[0], &sizes[1]);
		if ((*imgpoint)->img == NULL)
			return (ft_message("Error, can't open one of the texture\n", -1));
		(*imgpoint)->addr = mlx_get_data_addr((*imgpoint)->img,
				&(*imgpoint)->bits_per_pixel,
				&(*imgpoint)->line_length, &(*imgpoint)->endian);
	}
	if (i == 1)
		return (ft_message("Error, wrong texture format\n", -1));
	(*imgpoint)->img_size.x = sizes[0];
	(*imgpoint)->img_size.y = sizes[1];
	return (0);
}

int	ft_opentextures(t_display *display, t_texture *textures)
{
	if (ft_open_one_text(display, textures->west, &textures->wtext) == -1)
		return (-1);
	if (ft_open_one_text(display, textures->east, &textures->etext) == -1)
		return (-1);
	if (ft_open_one_text(display, textures->north, &textures->ntext) == -1)
		return (-1);
	if (ft_open_one_text(display, textures->south, &textures->stext) == -1)
		return (-1);
	return (0);
}
