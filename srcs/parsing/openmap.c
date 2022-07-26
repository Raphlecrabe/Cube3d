/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:26:40 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/25 15:11:35 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_openmap(char **argv)
{
	int		i;
	char	line[1];

	i = open(argv[1], O_RDONLY);
	if (i < 0)
		return (-1);
	if (read(i, line, 1) < 0)
		return (-1);
	close(i);
	i = open(argv[1], O_RDONLY);
	if (i < 0)
		return (-1);
	return (i);
}
