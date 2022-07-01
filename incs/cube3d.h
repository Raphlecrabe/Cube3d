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

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_cube
{
	int		fd;
	t_rgb	ceiling;
	t_rgb	floor;
	t_maps	*maps;
	char	*west;
	char	*east;
	char	*north;
	char	*south;
	int		parsed;
}	t_cube;

#endif