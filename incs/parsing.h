/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:46:53 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/28 14:09:58 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "cube3d.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

// Checkholes.c

int		ft_ishole(char **lines, int i, int j);

// Colourutils.c

char	*ft_getwhole(char *line, int i, t_memory *mem);
int		ft_testnumber(char **numbers);
int		ft_create_trgb(int t, int r, int g, int b);

// Error.c

int		ft_message(char *line, int i);

// Findcolour.c

int		ft_findcolour(t_cube *cube, char *line);

// Findpath.c

int		ft_findpath(t_cube *cube, char *line, int i);

// Initcube.c

int		ft_initcube(t_cube **cube, t_memory *mem);

// Map.c

int		ft_parsemap(t_cube *cube, char *line, int fd);

// Parsefc.c

int		ft_parseceiling(char *line, int i);
int		ft_parsefloor(char *line, int i);

// Parsemap.c

int		ft_addline(t_cube *cube, char *line, t_list **mapping);
int		ft_parseline(t_cube *cube, char *l);
int		ft_islast(t_cube *cube);

// Parseopen.c

int		ft_parseopen(t_cube *cube);

// Parseopen2.c

int		ft_parselines(t_cube *cube);

// Parseopenutils.c

int		ft_checknumbersc(char **lines, int i, int j);
int		ft_checkspacec(char **lines, int i, int j);
int		ft_isspace(int c);
int		ft_isnumbers(char c);

// Parsing.c

int		ft_fullparse(t_cube *cube, char **argv);

// Testcolours.c

int		ft_testsize(char **numbers);
int		ft_aredigits(char **numbers);
int		ft_arergb(char **numbers);

// Texture.c

int		ft_addtexture(t_cube *cube, char *line);

// Textureutils.c

int		ft_parsesouth(char *line, int i);
int		ft_parsenorth(char *line, int i);
int		ft_parseeast(char *line, int i);
int		ft_parsewest(char *line, int i);

// Openmap.c

int		ft_openmap(char **argv);

// Debugparsing.c

void	ft_printallcheck(t_cube *cube);
void	ft_printdoublechar(char **table);
void	ft_printtextures(t_cube *cube);

#endif