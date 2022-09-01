/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:03:38 by rafy              #+#    #+#             */
/*   Updated: 2022/08/31 18:22:15 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

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
