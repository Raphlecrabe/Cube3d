/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:16:27 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 10:16:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_vector2
{
	float	x;
	float	y;
}				t_vector2;

t_vector2	vector2(float x, float y);
t_vector2	vector2_add(t_vector2 v1, t_vector2 v2);
t_vector2	vector2_substract(t_vector2 v1, t_vector2 v2);
t_vector2	vector2_multiply(t_vector2 v, float m);
t_vector2	vector2_rotate(t_vector2 v, float angle);
t_vector2	vector2_normalize(t_vector2 v);
float		vector2_magnitude(t_vector2 v);
int			vector2_equals(t_vector2 v1, t_vector2 v2);

#endif