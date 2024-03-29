/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseopenutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:51:00 by rmonacho          #+#    #+#             */
/*   Updated: 2022/09/05 17:25:47 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_isnumbers(char c)
{
	if (c == '1' || c == '0' || c == 'W' || c == 'E' || c == 'N' || c == 'S')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_checkspacec(char **lines, int i, int j)
{
	if (ft_isspace(lines[j][i]) == 1)
		return (1);
	return (0);
}

int	ft_checknumbersc(char **lines, int i, int j)
{
	if (ft_isnumbers(lines[j][i]) == 1)
		return (1);
	return (0);
}
