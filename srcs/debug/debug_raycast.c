//DO NOT INCLUDE THIS FILE TO THE FINAL PROJECT
#include "../../incs/cube3d.h"
#include "../../incs/get_next_line.h"
#include "../../incs/display.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	**create_map(char *mapfile)
{
	char	*line;
	int		**map;
	int		i;
	int		j;
	int		fd;

	fd = open(mapfile, O_RDONLY);

	map = malloc(sizeof(int*) * 24);

	i = -1;
	while (++i < 24)	
		map[i] = malloc(sizeof(int) * 24);
	
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = -1;
		while (++j < 24)
			map[j][i] = line[j] - '0';
		line = get_next_line(fd);
		i++;
	}

	return (map);
}

void display_map(t_map *map)
{
	int x;
	int	y;

	y = -1;
	while (++y < map->heigth)
	{	
		x = -1;
		while (++x < map->width)
			printf("%d", map->map[x][y]);
		printf("\n");
	}
}

t_cube	init_cubdatas(char *mapfile)
{
	t_cube		cube;
	t_map		*map;
	t_player	*player;

	map = malloc(sizeof(t_map) * 1);
	map->map = create_map(mapfile);
	map->heigth = 24;
	map->width = 24;

	player = malloc(sizeof(t_player) * 1);
	player->x = 3;
	player->y = 2;
	player->angle = 0.0f;

	map->map[(int)player->x][(int)player->y] = 7;

	cube.player = player;
	cube.map = map;

	display_map(map);

	return (cube);
}

t_display init_displaydatas(t_cube *cube)
{
	t_display display;

	display.map = cube->map;
	display.player_pos = vector2(cube->player->x, cube->player->y);
	display.player_dir = vector2(0, 1);
	display.plane = vector2(0.66f, 0);
	display.screen_width = 30;

	return (display);
}

int main(int argc, char **argv)
{
	t_cube 		cube;
	t_display 	display;

	argc += 0;

	cube = init_cubdatas(argv[1]);

	display = init_displaydatas(&cube);

	display_screen(&display);

	cube.map += 0;
}