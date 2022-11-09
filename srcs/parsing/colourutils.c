/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:31:43 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/09 13:06:11 by fbelthoi         ###   ########.fr       */
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
		ft_putstr_fd("Error\nWrong texture format floor / ceiling\n", 2);
		return (-1);
	}
	if (ft_aredigits(numbers) == -1)
	{
		ft_putstr_fd("Error\nWrong texture format floor / ceiling\n", 2);
		return (-1);
	}
	if (ft_arergb(numbers) == -1)
	{
		ft_putstr_fd("Error\nWrong texture format floor / ceiling\n", 2);
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
		while (line[i] != '\0' && line[i] != ',' && line[i] != '\n')
		{
			whole[j] = line[i];
			i++;
			j++;
		}
		if (line[i] == '\0' || line[i] == '\n')
			break ;
		else
		{
			whole[j] = line[i];
			i++;
			j++;
		}
	}
}

char	*ft_getwhole(char *line, int i, t_memory *mem)
{
	char	*whole;
	int		j;

	j = 0;
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && line[i] != ',' && line[i] != '\n')
		{
			i++;
			j++;
		}
		if (line[i] == '\0' || line[i] == '\n')
			break ;
		i++;
		j++;
	}
	whole = ft_malloc_temp(sizeof(char), j + 1, mem);
	if (whole == NULL)
		return (NULL);
	whole[j] = '\0';
	i = i - j;
	j = 0;
	ft_fullwhole(whole, line, i);
	return (whole);
}
