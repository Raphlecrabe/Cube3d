/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:36:56 by rafy              #+#    #+#             */
/*   Updated: 2023/01/05 15:51:50 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

void	ft_setcolorfloor(t_display *display)
{
	if (SHADE != 1)
			display->textures->shade = display->textures->floor;
	else
	{
		display->textures->shade = create_trgb(0,
				((display->textures->floor >> 16) & 0xFF)
				* 0.2,
				((display->textures->floor >> 8) & 0xFF)
				* 0.2,
				(display->textures->floor & 0xFF)
				* 0.2);
	}
}

void	ft_drawpixel1(t_mlx_datas *texture, t_calc *calc,
		t_stripe stripe, int i)
{
	ft_getcolor1(texture, calc, i);
	ft_addshading(&calc->color, stripe.dist);
}

void	ft_drawpixel2(t_mlx_datas *texture, t_calc *calc,
		t_stripe stripe, int i)
{
	ft_getcolor2(texture, calc, i);
	ft_addshading(&calc->color, stripe.dist);
}

void	ft_drawceiling(int i, t_display *display, t_stripe stripe, int y)
{
	while (i < display->win_size.y * 0.5)
	{
		ft_setcolourceiling(display);
		my_mlx_pixel_put(display->view, stripe.x,
			y - i, display->textures->shade);
		i++;
	}
}

void	ft_drawfloor(int i, t_display *display, t_stripe stripe, int y)
{
	while (i <= display->win_size.y * 0.5)
	{
		ft_setcolorfloor(display);
		my_mlx_pixel_put(display->view, stripe.x,
			y + i, display->textures->shade);
		i++;
	}
}
