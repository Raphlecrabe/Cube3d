/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:31:43 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/01 16:06:56 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_testnumber(char **numbers)
{
	if (ft_testsize(numbers) == -1)
	{
		write(2, "Error, wrong texture format floor / ceiling\n", 45);
		return (-1);
	}
	if (ft_aredigits(numbers) == -1)
	{
		write(2, "Error, wrong texture format floor / ceiling\n", 45);
		return (-1);
	}
	if (ft_arergb(numbers) == -1)
	{
		write(2, "Error, wrong texture format floor / ceiling\n", 45);
		return (-1);
	}
	return (0);
}

void	ft_fullwhole(char *whole, char *line, int i)
{
	int		j;

	j = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && line[i] != ',')
		{
			whole[j] = line[i];
			i++;
			j++;
		}
		if (line[i] == '\0')
			break ;
		else
		{
			whole[j] = line[i];
			i++;
		}
	}
}

char	*ft_getwhole(char *line, int i)
{
	char	*whole;
	int		j;

	j = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && line[i] != ',')
		{
			i++;
			j++;
		}
		if (line[i] == '\0')
			break ;
		else
			i++;
	}
	whole = ft_malloc(sizeof(char), j + 1);
	if (whole == NULL)
		return (NULL);
	whole[j] = '\0';
	i = i - j;
	j = 0;
	ft_fullwhole(whole, line, i);
	return (whole);
}
