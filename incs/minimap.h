#ifndef MINIMAP_H
# define MINIMAP_H

# include "display.h"
# include "mlx_utils.h"

# define TILE_SIZE 12
# define MINIMAP_RAY_NB 20
# define TRANSPARENT 0xFF000000
# define BACKGROUND_COLOR 0x00AA80AA
# define TILE_COLOR 0x00880000

int			display_minimap(t_display *display);
t_vector2	minimap_size(t_map *map);

#endif