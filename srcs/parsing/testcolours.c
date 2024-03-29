/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcolours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:07:05 by rmonacho          #+#    #+#             */
/*   Updated: 2023/02/08 17:44:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_arergb(char **numbers)
{
	int	test;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (numbers[i][0] == '\0')
			return (-1);
		test = ft_atoi(numbers[i]);
		if (test < 0 || test > 255)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_aredigits(char **numbers)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		while (numbers[j][i] != '\0' && ft_isdigit(numbers[j][i]) == 1)
		{
			i++;
		}
		if (numbers[j][i] != '\0')
			return (-1);
		j++;
	}
	return (0);
}

int	ft_testsize(char **numbers)
{
	if (numbers == NULL)
		return (-1);
	if (numbers[0] == NULL)
		return (-1);
	if (numbers[1] == NULL)
		return (-1);
	if (numbers[2] == NULL)
		return (-1);
	if (numbers[3] != NULL)
		return (-1);
	return (0);
}
