/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:46:57 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/01 15:27:10 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
}	t_player;

typedef struct s_map
{
	int	**map;
	int	heigth;
	int	width;
}	t_map;

typedef struct s_check
{
	int	pfloor;
	int	pceil;
	int	pwest;
	int	peast;
	int	psouth;
	int	pnorth;
	int	player;
}	t_check;

typedef struct s_cube
{
	int			fd;
	int			ceiling;
	int			floor;
	t_map		*map;
	t_player	*player;
	char		*west;
	char		*east;
	char		*north;
	char		*south;
	t_check		check;
	int			parsed;
	char		*path;
}	t_cube;

#endif