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

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = malloc(sizeof(int) * 24);
		j = -1;
		while (++j < 24)
		{
			map[i][j] = line[j] - '0';
			printf("%d", map[i][j]);
		}
		printf("\n");
		line = get_next_line(fd);
		i++;
	}

	return (map);
}

t_cube	init_cubdatas(char *mapfile)
{
	t_cube		cube;
	t_map		map;
	t_player	player;

	player.x = 22;
	player.y = 12;
	player.angle = 0.0f;

	map.map = create_map(mapfile);
	map.heigth = 24;
	map.width = 24;

	cube.player = &player;
	cube.map = &map;

	return (cube);
}

int main(int argc, char **argv)
{
	t_cube cube;

	argc += 0;

	cube = init_cubdatas(argv[1]);

	display_screen(cube.map, cube.player);

	cube.map += 0;
}