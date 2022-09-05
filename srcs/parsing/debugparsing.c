/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:31:08 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/28 13:51:41 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/parsing.h"

void	ft_printallcheck(t_cube *cube)
{
	printf("pfloor : %d\n", cube->check.pfloor);
	printf("pceil : %d\n", cube->check.pceil);
	printf("pwest : %d\n", cube->check.pwest);
	printf("peast : %d\n", cube->check.peast);
	printf("psouth : %d\n", cube->check.psouth);
	printf("pnorth : %d\n", cube->check.pnorth);
	printf("player : %d\n", cube->check.player);
}

void	ft_printdoublechar(char **table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (table[i] != NULL)
	{
		j = 0;
		printf("---------TABLE[%d]---------\n", i);
		while (table[i][j] != '\0')
		{
			printf("%c", table[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_printtextures(t_cube *cube)
{
	printf("west = %s\n", cube->west);
	printf("east = %s\n", cube->east);
	printf("north = %s\n", cube->north);
	printf("south = %s\n", cube->south);
	printf("floor = %d\n", cube->floor);
	printf("ceiling = %d\n", cube->ceiling);
}

void	ft_printlist(t_list *list)
{
	while (list)
	{
		printf("list = %s\n", list->content);
		list = list->next;
	}
}
