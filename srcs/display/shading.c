/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:17:46 by rafy              #+#    #+#             */
/*   Updated: 2023/02/08 16:39:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include <math.h>

int	ft_getthird(char c, int color)
{
	if (c == 'r')
		return ((color >> 16) & 0xFF);
	if (c == 'g')
		return ((color >> 8) & 0xFF);
	if (c == 'b')
		return (color & 0xFF);
	return (0);
}

void	ft_addshading(int *color, float dist)
{
	float	r;
	float	g;
	float	b;

	if (SHADE != 1)
		return ;
	if (dist >= 14.0f)
	{
		*color = 0 << 16 | 0 << 8 | 0;
		return ;
	}
	if (dist <= 2.0)
	{
		r = ft_getthird('r', *color) * (1.0f / 1.0f);
		g = ft_getthird('g', *color) * (1.0f / 1.0f);
		b = ft_getthird('b', *color) * (1.0f / 1.0f);
		*color = create_trgb(0, r, g, b);
		return ;
	}
	r = ft_getthird('r', *color) * (1.0f / (dist / 1.9));
	g = ft_getthird('g', *color) * (1.0f / (dist / 1.9));
	b = ft_getthird('b', *color) * (1.0f / (dist / 1.9));
	*color = create_trgb(0, r, g, b);
}
