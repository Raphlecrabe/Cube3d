/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:16:23 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 10:16:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <unistd.h>
# include <sys/time.h>

typedef struct s_time
{
	int	sec;
	int	usec;
}				t_time;

t_time		gettime(void);
long int	get_time_since_started(t_time start_time);

#endif