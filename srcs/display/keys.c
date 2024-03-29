/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:58:34 by fbelthoi          #+#    #+#             */
/*   Updated: 2023/02/08 16:56:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/display.h"

int	key_press(int keycode, t_display *display)
{
	if (keycode <= KEY_MAX)
		display->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_display *display)
{
	if (keycode <= KEY_MAX)
		display->keys[keycode] = 0;
	return (0);
}

void	resetkeys(t_display *display)
{
	int	i;

	i = -1;
	while (++i <= KEY_MAX)
		display->keys[i] = 0;
}
