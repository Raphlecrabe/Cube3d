/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:30:41 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 09:30:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"
#include "../../incs/events.h"

void	rotate_player(t_display *display, float angle)
{
	display->player_dir = vector2_rotate(display->player_dir, angle);
	display->plane = vector2_rotate(display->plane, angle);
}

void	move(t_display *display, t_vector2 direction)
{
	display->player_pos.x += direction.x;
	display->player_pos.y += direction.y;
}
