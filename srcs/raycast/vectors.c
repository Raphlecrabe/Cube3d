/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:54:25 by marvin            #+#    #+#             */
/*   Updated: 2022/07/04 14:54:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vectors.h"
#include <math.h>

t_vector2	vector2(float x, float y)
{
	t_vector2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector2	vector2_add(t_vector2 vector_1, t_vector2 vector_2)
{
	t_vector2	result;

	result.x = vector_1.x + vector_2.x;
	result.y = vector_1.y + vector_2.y;
	return (result);
}

t_vector2	vector2_substract(t_vector2 vector_1, t_vector2 vector_2)
{
	t_vector2	result;

	result.x = vector_1.x - vector_2.x;
	result.y = vector_1.y - vector_2.y;
	return (result);
}

t_vector2	vector2_multiply(t_vector2 v, float m)
{
	v.x *= m;
	v.y *= m;
	return (v);
}

t_vector2	vector2_rotate(t_vector2 v, float angle)
{
	t_vector2 result;

	result.x = v.x * cos(angle) - v.y * sin(angle);
	result.y = v.x * sin(angle) + v.y * cos(angle);

	return (result);
}

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

int		vector2_equals(t_vector2 v1, t_vector2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}