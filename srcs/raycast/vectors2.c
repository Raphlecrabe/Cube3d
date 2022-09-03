/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:08:08 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 10:08:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vectors.h"
#include <math.h>

float	vector2_magnitude(t_vector2 v)
{
	return (sqrtf(pow(v.x, 2) + pow(v.y, 2)));
}

t_vector2	vector2_normalize(t_vector2 v)
{
	float	m;

	m = vector2_magnitude(v);
	return (vector2(v.x / m, v.y / m));
}

int	vector2_equals(t_vector2 v1, t_vector2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}
