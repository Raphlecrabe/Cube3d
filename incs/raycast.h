#ifndef RAYCAST_H
# define RAYCAST_H

#include "vector2.h"

typedef struct 	s_hit
{
	int	distance;
	int	side;
}				t_hit;

typedef struct	s_raycast
{
	float		cameraX;
	t_vector2	dir;
	t_vector2	pos;
	t_vector2	side_dist;
	t_vector2	delta_dist;
	float		perpWall_dist;
	t_vector2	step;
}				t_raycast;

typedef struct 	s_stripe
{
	int		x;
	float 	distance;
	void	*sprite
}				t_stripe;

typedef struct	s_wallcolor
{
	int	color;
}				t_wallcolor;

typedef struct	s_wallsprite
{
	int	fd;
}				t_wallsprite;

t_hit		raycast_hit();
t_stripe 	get_stripe(t_map, t_player, int);

#endif