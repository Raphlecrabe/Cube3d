/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:55:07 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 09:55:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/time.h"

t_time	gettime(void)
{
	struct timeval	tv;
	t_time			time;

	time.sec = -1;
	time.usec = -1;
	if (gettimeofday(&tv, NULL) == -1)
		return (time);
	time.sec = tv.tv_sec;
	time.usec = tv.tv_usec;
	return (time);
}

long int	get_time_since_started(t_time start_time)
{
	struct timeval	tv;
	long int		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = (tv.tv_usec - start_time.usec) / 1000
		+ ((tv.tv_sec - start_time.sec) * 1000);
	return (time);
}
