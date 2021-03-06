#ifndef VECTORS_H
# define VECTORS_H

typedef struct 	s_vector2
{
	float x;
	float y;
}				t_vector2;

t_vector2	vector2(float x, float y);
t_vector2	vector2_add(t_vector2 v1, t_vector2 v2);
t_vector2	vector2_substract(t_vector2 v1, t_vector2 v2);
t_vector2	vector2_multiply(t_vector2 v, float m);
t_vector2	vector2_normalize(t_vector2 v);
float		vector2_magnitude(t_vector2 v);

#endif