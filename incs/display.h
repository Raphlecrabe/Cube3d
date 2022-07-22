#ifndef DISPLAY_H
# define DISPLAY_H

#include "cube3d.h"
#include "vectors.h"
#include "garbage.h"

typedef struct s_display
{
	t_map		*map;
	t_vector2	player_pos;
	t_vector2	player_dir;
	t_vector2	plane;
	t_memory	*mem;
	int			screen_width;

}				t_display;

void	display_screen(t_display *display);

#endif