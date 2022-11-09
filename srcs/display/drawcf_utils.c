/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:03:38 by rafy              #+#    #+#             */
/*   Updated: 2022/11/02 14:10:45 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

void	ft_setcolorfloor(t_display *display)
{
	if (SHADE == 0)
	{
			display->textures->shade = display->textures->floor;
	}
	if (SHADE == 1)
	{
		display->textures->shade = create_trgb(0,
				ft_getthird('r', display->textures->floor)
				* 0.10,
				ft_getthird('g', display->textures->floor)
				* 0.10,
				ft_getthird('b', display->textures->floor)
				* 0.10);
	}
}

void	ft_andreutilsceiling(int *x, int *y, int r, int *d)
{
	if (*d >= 2 * *x)
	{
		*d -= 2 * *x + 1;
		*x = *x + 1;
	}
	else if (*d < 2 * (r - *y))
	{
		*d += 2 * *y - 1;
		*y = *y - 1;
	}
	else
	{
		*d += 2 * (*y - *x - 1);
		*y = *y - 1;
		*x = *x + 1;
	}
}

void	ft_andrescircleceiling(int xc, int yc, int r, t_display *display)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		my_mlx_pixel_put(display->view, xc + x,
			yc + y, display->textures->shade);
		my_mlx_pixel_put(display->view, xc + y,
			yc + x, display->textures->shade);
		my_mlx_pixel_put(display->view, xc - x,
			yc + y, display->textures->shade);
		my_mlx_pixel_put(display->view, xc - y,
			yc + x, display->textures->shade);
		ft_andreutilsceiling(&x, &y, r, &d);
	}
}

void	ft_drawceilingshade(t_display *display)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_setcolourceiling(display);
	while (i < display->view->img_size.x)
	{
		while (j < display->view->img_size.y / 2)
		{
			my_mlx_pixel_put(display->view, i, j, display->textures->shade);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_drawfloorshade(t_display *display)
{
	int	i;
	int	j;

	i = 0;
	j = display->view->img_size.y / 2;
	ft_setcolorfloor(display);
	while (i < display->view->img_size.x)
	{
		while (j < display->view->img_size.y)
		{
			my_mlx_pixel_put(display->view, i, j, display->textures->shade);
			j++;
		}
		j = display->view->img_size.y / 2;
		i++;
	}
}
