#ifndef VECTORS_H
# define VECTORS_H

typedef struct 	s_vector2
{
	float x;
	float y;
}				t_vector2;

t_vector2	vector2(float x, float y);
t_vector2	vector2_substract(t_vector2 v1, t_vector2 v2);
t_vector2	vector_by_matrix(t_vector2 v, t_vector2 m);

#endif