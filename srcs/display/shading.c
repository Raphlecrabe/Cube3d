/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:17:46 by rafy              #+#    #+#             */
/*   Updated: 2023/01/05 13:48:48 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include <math.h>

void	ft_addshading(int *color, float dist)
{
	int		copy;
	float	r;
	float	g;
	float	b;

	if (SHADE != 1)
		return ;
	copy = *color;
	if (dist >= 14.0f)
	{
		*color = 0 << 16 | 0 << 8 | 0;
		return ;
	}
	if (dist <= 2.0)
	{
		r = ((*color >> 16) & 0xFF);
		g = ((*color >> 8) & 0xFF);
		b = (*color & 0xFF);
		*color = create_trgb(0, r, g, b);
		return ;
	}
	r = ((*color >> 16) & 0xFF) * (1.0f / (dist / 1.9));
	g = ((*color >> 8) & 0xFF) * (1.0f / (dist / 1.9));
	b = (*color & 0xFF) * (1.0f / (dist / 1.9));
	*color = create_trgb(0, r, g, b);
}
