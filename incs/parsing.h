/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:46:53 by rmonacho          #+#    #+#             */
/*   Updated: 2022/06/30 13:34:38 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "cube3d.h"
# include "get_next_line.h"

int		ft_fullparse(t_cube *cube, char **argv);
int		ft_addtexture(t_cube *cube, char *line);
int		ft_parsewest(t_cube *cube, char *line, int i);
int		ft_parseeast(t_cube *cube, char *line, int i);
int		ft_parsenorth(t_cube *cube, char *line, int i);
int		ft_parsesouth(t_cube *cube, char *line, int i);
int		ft_testsize(char **numbers);
int		ft_aredigits(char **numbers);
int		ft_arergb(char **numbers);
int		ft_parsefloor(char *line, int i);
int		ft_parseceiling(char *line, int i);
int		ft_findpath(t_cube *cube, char *line, int i);
int		ft_findcolour(t_cube *cube, char *line);
char	*ft_getwhole(char *line, int i);
int		ft_testnumber(char **numbers);
int		ft_create_trgb(int t, int r, int g, int b);

#endif