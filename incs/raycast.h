/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:18:47 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/21 17:18:47 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "vectors.h"
# include "cube3d.h"
# include "display.h"

typedef struct s_hit
{
	t_vector2	pos;
	float		distance_adapted;
	float		true_distance;
	int			side;
	int			hit;
}				t_hit;

typedef struct s_raycast
{
	float		camera_x;
	t_vector2	dir;
	t_vector2	mappos;
	t_vector2	side_dist;
	t_vector2	delta_dist;
	t_vector2	step;
}				t_raycast;

typedef struct s_stripe
{
	int			x;
	t_vector2	pos;
	int			height;
	int			perp_wall_dist;
	int			side;
	float		dist;
	void		*sprite;
}				t_stripe;

typedef struct s_wallcolor
{
	char	*color;
}				t_wallcolor;

typedef struct s_wallsprite
{
	int	fd;
}				t_wallsprite;

# define COLOR_BLUE "blue";
# define COLOR_GREEN "green";
# define COLOR_RED "red";
# define COLOR_WHITE "white";

t_hit		raycast_hit(int x, t_display *display);
t_stripe	get_stripe(int x, t_display *display);
t_vector2	get_step(t_raycast ray);
t_vector2	get_side(t_raycast ray, t_vector2 pos);

#endif