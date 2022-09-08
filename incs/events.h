/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:11:14 by marvin            #+#    #+#             */
/*   Updated: 2022/09/08 11:45:50 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "cube3d.h"
# include "display.h"

typedef struct s_collision
{
	t_vector2	player_pos;
	float		movespeed;
	float		screenplane_width;
	t_map		*map;
}				t_collision;

# define DEG_TO_RAD 0.01745f
# define MOVE_SPEED 0.1f
# define ROTATE_SPEED 10.0f
# define MOUSE_ROTATE_SPEED 0.5f

# define A_KEY_MAC 0
# define B_KEY_MAC 11
# define C_KEY_MAC 8
# define D_KEY_MAC 2
# define E_KEY_MAC 14
# define F_KEY_MAC 3
# define G_KEY_MAC 5
# define H_KEY_MAC 4
# define I_KEY_MAC 34
# define J_KEY_MAC 38
# define K_KEY_MAC 40
# define L_KEY_MAC 37
# define M_KEY_MAC 46
# define N_KEY_MAC 45
# define O_KEY_MAC 31
# define P_KEY_MAC 35
# define Q_KEY_MAC 12
# define R_KEY_MAC 15
# define S_KEY_MAC 1
# define T_KEY_MAC 17
# define U_KEY_MAC 32
# define V_KEY_MAC 9
# define W_KEY_MAC 13
# define X_KEY_MAC 7
# define Y_KEY_MAC 16
# define Z_KEY_MAC 6
# define UP_KEY_MAC 126
# define LEFT_KEY_MAC 123
# define RIGHT_KEY_MAC 124
# define DOWN_KEY_MAC 125
# define ESCAPE_KEY_MAC 53

# define A_KEY_LIN 97
# define B_KEY_LIN 98
# define C_KEY_LIN 99
# define D_KEY_LIN 100
# define E_KEY_LIN 101
# define F_KEY_LIN 102
# define G_KEY_LIN 103
# define H_KEY_LIN 104
# define I_KEY_LIN 105
# define J_KEY_LIN 106
# define K_KEY_LIN 107
# define L_KEY_LIN 108
# define M_KEY_LIN 109
# define N_KEY_LIN 110
# define O_KEY_LIN 111
# define P_KEY_LIN 112
# define Q_KEY_LIN 113
# define R_KEY_LIN 114
# define S_KEY_LIN 115
# define T_KEY_LIN 116
# define U_KEY_LIN 117
# define V_KEY_LIN 118
# define W_KEY_LIN 119
# define X_KEY_LIN 120
# define Y_KEY_LIN 121
# define Z_KEY_LIN 122
# define UP_KEY_LIN 65362
# define LEFT_KEY_LIN 65361
# define RIGHT_KEY_LIN 65363
# define DOWN_KEY_LIN 65364
# define ESCAPE_KEY_LIN 65307

int		key_hook(int keycode, t_display *display);
int		handle_mouse(int x, int y, t_display *display);
void	rotate_player(t_display *display, float angle);
void	move(t_display *display, t_vector2 direction);
int		is_wall(char c);

#endif