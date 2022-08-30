//DO NOT INCLUDE THIS FILE TO THE FINAL PROJECT
#include "../../incs/cube3d.h"
#include "../../incs/get_next_line.h"
#include "../../incs/display.h"
#include "../../incs/garbage.h"
#include "../../incs/events.h"
#include "../../incs/mlx_utils.h"
#include "../../incs/vectors.h"
#include "../../incs/minimap.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

char	**create_map(char *mapfile, t_memory *mem)
{
	char	*line;
	char	**lines;
	int		i;
	int		j;
	int		fd;

	fd = open(mapfile, O_RDONLY);

	lines = ft_malloc_const(25, sizeof(char *), mem);
	lines[24] = NULL;

	i = -1;
	while (++i < 24)
	{
		lines[i] = ft_malloc_const(25, sizeof(char), mem);
		lines[i][24] = '\0';
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = -1;
		while (++j < 24)
			lines[j][i] = line[j];
		free(line);
		line = get_next_line(fd);
		i++;
	}

	return (lines);
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
			printf("%c", map->lines[x][y]);
		printf("\n");
	}
}

t_cube	init_cubdatas(char *mapfile, t_memory *mem)
{
	t_cube		cube;
	t_map		*map;
	t_playerinit	*player;

	map = ft_malloc_const(1, sizeof(t_map), mem);
	map->lines = create_map(mapfile, mem);
	map->heigth = 24;
	map->width = 24;

	player = ft_malloc_const(1, sizeof(t_playerinit), mem);
	player->coord = vector2(15.5f, 11.5f);
	player->angle = vector2(0.0f, 0.0f);

	map->lines[(int)player->coord.x][(int)player->coord.y] = 7;

	cube.playerinit = player;
	cube.map = map;

	display_map(map);

	return (cube);
}

t_display init_displaydatas(t_cube *cube, t_memory *mem)
{
	t_display display;

	display.map = cube->map;
	display.player_pos = cube->playerinit->coord;
	display.player_dir = vector2(0, 1);
	display.plane = vector2(0.66f, 0);
	display.screen_width = 50;
	display.win_size = vector2(800, 800);
	display.mem = mem;

	return (display);
}

t_mlx_datas init_mlxdatas(void *mlx, t_vector2 img_size)
{
	t_mlx_datas datas;

	datas.img_size = img_size;
	datas.img = mlx_new_image(mlx, datas.img_size.x, datas.img_size.y);
	datas.addr = mlx_get_data_addr(datas.img, &datas.bits_per_pixel, &datas.line_length, &datas.endian);

	return (datas);
}

int main(int argc, char **argv)
{
	t_cube 		cube;
	t_display 	display;
	t_memory	mem;
	t_mlx_datas view;
	t_mlx_datas	minimap;

	void	*mlx;
	void	*mlx_win;

	argc += 0;
	argv += 0;

	mem.used = NULL;

	cube = init_cubdatas(argv[1], &mem);

	display = init_displaydatas(&cube, &mem);

	mlx = mlx_init();

	view = init_mlxdatas(mlx, display.win_size);
	minimap = init_mlxdatas(mlx, vector2(300, 300));

	mlx_win = mlx_new_window(mlx, display.win_size.x, display.win_size.y, "cub3d");

	display.mlx = mlx;
	display.mlx_win = mlx_win;
	display.view = &view;
	display.minimap = &minimap;
	display.mousePos = vector2(display.screen_width / 2, 0);

	display_screen(&display);

	display_minimap(&display);

	mlx_key_hook(mlx_win, key_hook, &display);
	mlx_loop_hook(mlx, loop_hook, &display);
	mlx_loop(mlx);

	ft_freemem(&mem);
}
