//DO NOT INCLUDE THIS FILE TO THE FINAL PROJECT
#include "../../incs/cube3d.h"
#include "../../incs/get_next_line.h"
#include "../../incs/display.h"
#include "../../incs/garbage.h"
#include "../../incs/events.h"
#include "../../incs/mlx_utils.h"
#include "../../incs/vectors.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>

int	**create_map(char *mapfile, t_memory *mem)
{
	char	*line;
	int		**map;
	int		i;
	int		j;
	int		fd;

	fd = open(mapfile, O_RDONLY);

	map = ft_malloc_const(24, sizeof(int*), mem);

	i = -1;
	while (++i < 24)	
		map[i] = ft_malloc_const(24, sizeof(int), mem);
	
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = -1;
		while (++j < 24)
			map[j][i] = line[j] - '0';
		free(line);
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

t_cube	init_cubdatas(char *mapfile, t_memory *mem)
{
	t_cube		cube;
	t_map		*map;
	t_player	*player;

	map = ft_malloc_const(1, sizeof(t_map), mem);
	map->map = create_map(mapfile, mem);
	map->heigth = 24;
	map->width = 24;

	player = ft_malloc_const(1, sizeof(t_player), mem);
	player->x = 12;
	player->y = 12;
	player->angle = 0.0f;

	map->map[(int)player->x][(int)player->y] = 7;

	cube.player = player;
	cube.map = map;

	display_map(map);

	return (cube);
}

t_display init_displaydatas(t_cube *cube, t_memory *mem)
{
	t_display display;

	display.map = cube->map;
	display.player_pos = vector2(cube->player->x, cube->player->y);
	display.player_dir = vector2(0, 1);
	display.plane = vector2(0.66f, 0);
	display.screen_width = 30;
	display.mem = mem;

	return (display);
}

t_mlx_datas init_mlxdatas(void *mlx)
{
	t_mlx_datas datas;

	datas.win_size = vector2(500, 500);
	datas.img = mlx_new_image(mlx, datas.win_size.x, datas.win_size.y);
	datas.addr = mlx_get_data_addr(datas.img, &datas.bits_per_pixel, &datas.line_length, &datas.endian);

	return (datas);
}

int main(int argc, char **argv)
{
	t_cube 		cube;
	t_display 	display;
	t_memory	mem;
	t_mlx_datas datas;

	void	*mlx;
	void	*mlx_win;

	argc += 0;
	argv += 0;

	mem.used = NULL;

	cube = init_cubdatas(argv[1], &mem);

	display = init_displaydatas(&cube, &mem);

	mlx = mlx_init();

	datas = init_mlxdatas(mlx);

	mlx_win = mlx_new_window(mlx, datas.win_size.x, datas.win_size.y, "cub3d");

	display.mlx = mlx;
	display.mlx_win = mlx_win;
	display.datas = &datas;

	display_screen(&display);

	mlx_key_hook(mlx_win, key_hook, &display);
	mlx_loop(mlx);

	ft_freemem(&mem);
}