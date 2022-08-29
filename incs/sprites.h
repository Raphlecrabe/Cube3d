#ifndef SPRITES_H
# define SPRITES_H

typedef struct	s_sprite_texture
{
	int	x;
	int	y;
	int	height;
	int	width;
}				t_sprite_texture;

typedef struct	s_sprite
{
	t_vector2 world_pos;
	t_vector2 relative_pos;
	t_vector2 transform;
	float dist;
	t_vector2 drawStart;
	t_vector2 drawEnd;
	int	onScreenHeight;
	int onScreenWidth;
	int	screenX;
	t_sprite_texture tex;
}				t_sprite;

#endif