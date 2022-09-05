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

int	display_screen(t_display *display)
{
	t_stripe	stripe;
	int			x;

	x = 0;
	if (img_clean(display->mlx, display->view) == 0)
		return (0);
	display->hitpos = ft_malloc_temp(sizeof(t_vector2),
			display->screen_width, display->mem);
	ft_drawcf(display);
	if (display->hitpos == NULL)
		return (0);
	while (x < display->screen_width)
	{
		stripe = get_stripe(x, display);
		if (stripe.height > display->win_size.y)
			stripe.height = display->win_size.y;
		ft_drawwalls(stripe, display);
		display->hitpos[x] = stripe.pos;
		//display->z_buffer[x] = stripe.perpWallDist;
		x++;
	}
	return (1);
}

int	ft_maindisplay(t_cube *cube)
{
	t_display	*display;

	if (ft_initdisplay(&display, cube) == -1)
		return (0);
	if (ft_opentextures(display, display->textures) == -1)
		return (0);
	if (display_all(display) == 0)
		return (0);
	mlx_key_hook(display->mlx_win, key_hook, display);
	//mlx_loop_hook(display->mlx, loop_hook, display);
	mlx_hook(display->mlx_win, 17, (1L<<2), exit_cub, display);
	mlx_loop(display->mlx);
	return (1);
}

int	display_all(t_display *display)
{
	ft_freetemp(display->mem);
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
