/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:17:46 by rafy              #+#    #+#             */
/*   Updated: 2022/08/31 13:03:05 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include <math.h>

float	ft_getthird(char c, int color)
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
	int		copy;
	float	r;
	float	g;
	float	b;

	copy = *color;
	if (dist >= 10.0f)
	{
		copy = 0 << 16 | 0 << 8 | 0;
		*color = copy;
		return ;
	}
	dist = dist;
	r = ft_getthird('r', *color) * (1.0f - (0.10f * dist));
	g = ft_getthird('g', *color) * (1.0f - (0.10f * dist));
	b = ft_getthird('b', *color) * (1.0f - (0.10f * dist));
	*color = create_trgb(0, r, g, b);
}
