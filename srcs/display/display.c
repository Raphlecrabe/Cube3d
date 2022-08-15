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
#include "../../incs/raycast.h"
#include "../../incs/mlx_utils.h"
#include "../../incs/vectors.h"
#include "../../incs/minimap.h"
#include <mlx.h>
#include <stdio.h>

static void	display_stripe(t_stripe stripe, t_mlx_datas *datas)
{
	stripe.height += 0;
	fill_img(datas, 0x000000FF);
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
		display_stripe(stripe, display->view);
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
	if (ft_display_screen(display) == -1)
		return (-1);
	
}
