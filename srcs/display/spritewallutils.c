/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritewallutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:10:53 by raphael           #+#    #+#             */
/*   Updated: 2022/09/01 16:11:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float	ft_decimal(float x)
{
	float	a;

	a = floor(x);
	return (x - a);
}
