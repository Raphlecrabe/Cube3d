/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:20:14 by marvin            #+#    #+#             */
/*   Updated: 2022/08/04 21:20:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/events.h"
#include "../../incs/display.h"
#include "../../incs/minimap.h"
#include <mlx.h>

int loop_hook(t_display *display)
{
	int	x;
	int	y;
	int offset;

	mlx_mouse_get_pos(display->mlx, display->mlx_win, &x, &y);
	if (x == display->mousePos.x)
		return (1);
	offset = x - display->mousePos.x;
	display->mousePos.x = x;
	rotate_player(display, offset * MOUSE_ROTATE_SPEED);
	return (display_all(display));
}