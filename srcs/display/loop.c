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

int	handle_mouse(int x, int y, t_display *display)
{
	int	offset;

	y += 0;
	if (x == display->mouse_pos.x)
		return (1);
	offset = x - display->mouse_pos.x;
	display->mouse_pos.x = x;
	rotate_player(display, offset * MOUSE_ROTATE_SPEED * DEG_TO_RAD);
	display_all(display);
	return (1);
}
