/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:36:56 by rafy              #+#    #+#             */
/*   Updated: 2022/09/05 12:55:44 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

void	ft_andreutilsfloor(int *x, int *y, int r, int *d)
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

void	ft_andrescirclefloor(int xc, int yc, int r, t_display *display)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = r - 1;
	while (y >= x)
	{
		if (display->textures->shade != 0)
		{
			my_mlx_pixel_put(display->view, xc - x,
				yc - y, display->textures->shade);
			my_mlx_pixel_put(display->view, xc - y,
				yc - x, display->textures->shade);
			my_mlx_pixel_put(display->view, xc + x,
				yc - y, display->textures->shade);
			my_mlx_pixel_put(display->view, xc + y,
				yc - x, display->textures->shade);
		}
		ft_andreutilsfloor(&x, &y, r, &d);
	}
}

void	ft_drawfloor(t_display *display)
{
	int	x;
	int	y;
	int	r;

	x = display->win_size.x / 2;
	y = display->win_size.y - 1;
	r = 0;
	while (r < display->win_size.y / 2)
	{
		if (r > 340)
			display->textures->shade = 0x00000000;
		if (r <= 340)
			display->textures->shade = create_trgb(0,
					ft_getthird('r', display->textures->floor)
					* 0.025 * (400 - r) / 15,
					ft_getthird('g', display->textures->floor)
					* 0.025 * (400 - r) / 15,
					ft_getthird('b', display->textures->floor)
					* 0.025 * (400 - r) / 15);
		ft_andrescirclefloor(x, y, r, display);
		r++;
	}
}

void	ft_drawshade(t_display *display)
{
	ft_drawceilingshade(display);
	ft_drawfloorshade(display);
}

void	ft_drawcf(t_display *display)
{
	ft_drawshade(display);
	ft_drawfloor(display);
}
