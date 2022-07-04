#ifndef VECTORS_H
# define VECTORS_H

typedef struct 	s_vector2
{
	int x;
	int y;
}				t_vector2;

t_vector2	vector2(int, int);
t_vector2	vector2_substract(t_vector2, t_vector2);

#endif