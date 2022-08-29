#ifndef SPRITES_H
# define SPRITES_H

# define UDIV 1
# define VDIV 1
# define VMOVE 0

# define ANIM_SPEED 1

typedef struct s_display t_display;

typedef struct	s_sprite_texture
{
	int	x;
	int	y;
	int	height;
	int	width;
	int	*fd;
	int	frame_number;
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
	int	vMoveScreen;
}				t_sprite;

typedef struct 	s_sprite_datas
{
	t_sprite	*sprites;
	int			number;
}				t_sprite_datas;

void	display_sprite(t_display *display);

#endif