# include "../../incs/display.h"
# include "../../incs/garbage.h"
# include "../../incs/mlx_utils.h"
# include <math.h>

static void calc_dist(t_display *display, t_sprite *sprites)
{
	t_vector2	pos_to_player;
	int			i;

	i = 0;
	while (i < display->spriteDatas->number)
	{
		pos_to_player = vector2_substract(sprites[i].world_pos, display->player_pos);
		sprites[i].relative_pos = pos_to_player;
		sprites[i].dist = pow(pos_to_player.x, 2) + pow(pos_to_player.y, 2);
		i++;
	}
}

static void	bubbleSortSprite(t_sprite *sprites, int n)
{
	t_sprite temp;
	int	i;

	i = 0;
	while (i + 1 < n)
	{
		if (sprites[i].dist < sprites[i + 1].dist)
		{
			temp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

static t_vector2	get_transform(t_display *display, float invDet, t_sprite sprite)
{
	t_vector2 transform;
	t_vector2 dir;
	t_vector2 plane;
	t_vector2 spritePos;

	dir = display->player_dir;
	plane = display->plane;
	spritePos = sprite.relative_pos;
	transform.x = invDet * (dir.y * spritePos.x - dir.x * spritePos.y);
	transform.y = invDet * (- plane.y * spritePos.x + plane.x * spritePos.y);

	return (transform);
}

static void	calc_sprite_height(int screen_height, t_sprite *sprite)
{
	int			height;
	int			drawStartY;
	int			drawEndY;

	height = (int)fabs(screen_height / sprite->transform.y);
	drawStartY = - height / 2 + screen_height / 2;
	if (drawStartY < 0)
		drawStartY = 0;
	drawEndY = height / 2 + screen_height / 2;
	if (drawEndY >= screen_height)
		drawEndY = screen_height - 1;
	sprite->onScreenHeight = height;
	sprite->drawStart.y = drawStartY;
	sprite->drawEnd.y = drawEndY;
}

static void calc_sprite_width(int screen_height, int screen_width, t_sprite *sprite)
{
	int			width;
	int			drawStartX;
	int			drawEndX;

	width = (int)fabs(screen_height / sprite->transform.y);
	drawStartX = - width / 2 + sprite->screenX;
	if (drawStartX < 0)
		drawStartX = 0;
	drawEndX = width / 2 + sprite->screenX;
	if (drawEndX >= screen_width)
		drawEndX = screen_width - 1;
	sprite->onScreenWidth = width;
	sprite->drawStart.x = drawStartX;
	sprite->drawEnd.x = drawEndX;
}

static int isDrawable(t_display *display, t_sprite sprite, int x)
{
	// if
	// it's in front of camera plane so you don't see things behind you
	// it's on the screen (left)
	// it's on the screen (right)
	// z_buffer, with perpendicular distance
	return (sprite.transform.y > 0
			&& x > 0
			&& x < display->screen_width
			&& sprite.transform.y < display->z_buffer[x]);
}

static void draw_sprite(t_display *display, t_sprite sprite)
{
	int			x;
	int			y;

	x = sprite.drawStart.x - 1;
	while (++x < sprite.drawEnd.x)
	{
		sprite.tex.x = (int)(256 * (x - (-sprite.onScreenWidth / 2 + sprite.screenX))
						* sprite.tex.width / sprite.onScreenWidth) / 256;
		if (isDrawable(display, sprite, x))
		{
			y = sprite.drawStart.y - 1;
			while (++y < sprite.drawEnd.y)
			{
				//draw
			}
		}
	}
}

static void	project(t_display *display, t_sprite *sprites)
{
	float		invDet;
	int	i;

	i = 0;
	invDet = 1.0f / (display->plane.x * display->player_dir.y
					- display->player_dir.x * display->plane.y);
	while (i > display->spriteDatas->number)
	{
		sprites[i].transform = get_transform(display, invDet, sprites[i]);
		sprites[i].screenX = (int)((display->screen_width / 2)
								* (1 + sprites[i].transform.x / sprites[i].transform.y));
		calc_sprite_height(display->win_size.y, &sprites[i]);
		calc_sprite_width(display->win_size.y, display->win_size.x, &sprites[i]);
		draw_sprite(display, sprites[i]);
		i++;
	}
}

void display_sprites(t_display *display)
{
	calc_dist(display, display->spriteDatas->sprites);
	bubbleSortSprite(display->spriteDatas->sprites, display->spriteDatas->number);
	project(display, display->spriteDatas->sprites);
	mlx_put_image_to_window(display->mlx, display->mlx_win,
		display->view->img, 0, 0);
}