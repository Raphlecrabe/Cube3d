/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritewall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:11:24 by raphael           #+#    #+#             */
/*   Updated: 2022/08/18 17:12:06 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

void	ft_getcolor2(t_mlx_datas *texture, t_calc *calc, int i)
{
	int		ycalc;
	char	*color;

	ycalc = calc->ytext + ((i * texture->img_size.y) / calc->height);
	color = texture->addr + (ycalc * texture->line_length
			+ calc->widthwall * (texture->bits_per_pixel / 8));
	calc->color = *(unsigned int *)color;
}

void	ft_getcolor1(t_mlx_datas *texture, t_calc *calc, int i)
{
	int		ycalc;
	char	*color;

	ycalc = calc->ytext - ((i * (int)texture->img_size.y) / calc->height);
	color = texture->addr + (ycalc * texture->line_length
			+ calc->widthwall * (texture->bits_per_pixel / 8));
	calc->color = *(unsigned int *)color;

}

void	ft_drawone(t_stripe stripe, t_display *display,
	t_calc *calc, t_mlx_datas *texture)
{
	int		i;
	int		y;

	i = 0;
	calc->height = stripe.height;
	y = (int)display->view->img_size.y / 2
		+ (int)display->view->img_size.y % 2 - 1;
	calc->ytext = (int)texture->img_size.y / 2
		+ (int)texture->img_size.y % 2 - 1;
	while (i < stripe.height / 2 + stripe.height % 2)
	{
		ft_getcolor1(texture, calc, i);
		my_mlx_pixel_put(display->view, stripe.x, y - i, calc->color);
		i++;
	}
	i = 1;
	while (i < stripe.height / 2 + stripe.height % 2)
	{
		ft_getcolor2(texture, calc, i);
		my_mlx_pixel_put(display->view, stripe.x, y + i, calc->color);
		i++;
	}
}

void	ft_drawwall(t_stripe stripe,
	t_display *display, t_mlx_datas *texture)
{
	t_calc	calc;

	calc.relativepos = ft_decimal(stripe.pos.x) + ft_decimal(stripe.pos.y);
	calc.widthwall = (int)(calc.relativepos * texture->img_size.x);
	ft_drawone(stripe, display, &calc, texture);
}

void	ft_drawwalls(t_stripe stripe, t_display *display)
{
	stripe.side = 0;
	if (stripe.side == 0)
		ft_drawwall(stripe, display, display->textures->wtext);
	if (stripe.side == 1)
		ft_drawwall(stripe, display, display->textures->etext);
	if (stripe.side == 2)
		ft_drawwall(stripe, display, display->textures->stext);
	if (stripe.side == 3)
		ft_drawwall(stripe, display, display->textures->ntext);
}
