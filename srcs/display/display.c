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

static void	display_stripe(t_stripe stripe, t_mlx_datas *datas, float size)
{
	int	i;
	int	y;

	i = 0;
	y = (int)size / 2 + (int)size % 2 - 1;
	while (i < stripe.height / 2 + stripe.height % 2)
	{
		my_mlx_pixel_put(datas, stripe.x, y - i, 0x00FF0000);
		i++;
	}
	i = 1;
	while (i < stripe.height / 2 + stripe.height % 2)
	{
		my_mlx_pixel_put(datas, stripe.x, y + i, 0x00FF0000);
		i++;
	}
}

int	display_screen(t_display *display)
{
	t_stripe	stripe;
	int			x;

	x = 0;
	img_clean(display->mlx, display->view);
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
		display_stripe(stripe, display->view, display->win_size.y);
		display->hitpos[x] = stripe.pos;
		x++;
	}
	mlx_put_image_to_window(display->mlx, display->mlx_win,
		display->view->img, 0, 0);
	return (1);
}

int	ft_maindisplay(t_cube *cube)
{
	t_display	*display;

	if (ft_initdisplay(&display, cube) == -1)
		return (-1);
	if (display_screen(display) == -1)
		return (-1);
	mlx_key_hook(display->mlx_win, key_hook, display);
	mlx_loop_hook(display->mlx_win, loop_hook, display);
	mlx_loop(display->mlx);
	return (0);
}

int	display_all(t_display *display)
{
	if (!display_screen(display))
		return (0);
	if (!display_minimap(display))
		return (0);
	ft_freetemp(display->mem);
	return (1);
}
