/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:57:39 by marvin            #+#    #+#             */
/*   Updated: 2022/07/04 15:57:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

int	display_loop(t_display *display)
{
	if (display_all(display) == 1)
		return (1);
	exit_cub(display);
	return (0);
}

int	display_screen(t_display *display)
{
	t_stripe	stripe;
	int			x;

	x = 0;
	ft_drawcf(display);
	while (x < display->screen_width)
	{
		stripe = get_stripe(x, display);
		ft_drawwalls(stripe, display);
		display->hitpos[x] = stripe.pos;
		x++;
	}
	return (1);
}

int	ft_maindisplay(t_cube *cube)
{
	t_display	*display;

	if (ft_initdisplay(&display, cube) == -1)
		exit_cub(display);
	if (ft_opentextures(display, display->textures) == -1)
		exit_cub(display);
	if (display_all(display) == 0)
		exit_cub(display);
	mlx_hook(display->mlx_win, ON_KEYDOWN, (1L<<0), key_press, display);
	mlx_hook(display->mlx_win, ON_KEYUP, (1L<<1), key_release, display);
	mlx_hook(display->mlx_win, 6, 0, handle_mouse, display);
	mlx_hook(display->mlx_win, 17, (1L << 2), exit_cub, display);
	mlx_loop_hook(display->mlx, display_loop, display);
	mlx_loop(display->mlx);
	return (1);
}

int	display_all(t_display *display)
{
	ft_freetemp(display->mem);
	key_hook(display);
	if (display_screen(display))
	{
		if (display_minimap(display))
		{
			mlx_put_image_to_window(display->mlx, display->mlx_win,
				display->view->img, 0, 0);
			return (1);
		}
	}
	exit_cub(display);
	return (0);
}
