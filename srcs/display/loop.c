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
#include "../../incs/time.h"
#include <mlx.h>

static int handle_time(t_display *display)
{
	display->timeSinceStarted = getTimeSinceStarted(display->startTime);
	if (display->timeSinceStarted == -1)
		return (0);
	printf("timeSinceStarted: %ld\n", display->timeSinceStarted);
	return (1);
}

static int handle_mouse(t_display *display)
{
	int	x;
	int	y;
	int offset;

	mlx_mouse_get_pos(display->mlx, display->mlx_win, &x, &y);
	if (x == display->mousePos.x)
		return (1);
	offset = x - display->mousePos.x;
	display->mousePos.x = x;
	rotate_player(display, offset * MOUSE_ROTATE_SPEED * DEG_TO_RAD);
	return (display_all(display));
}

int loop_hook(t_display *display)
{
	if (handle_mouse(display) == 0)
		return (0);
	if (handle_time(display) == 0)
		return (0);
	return (1);
}