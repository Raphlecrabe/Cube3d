/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:00:18 by marvin            #+#    #+#             */
/*   Updated: 2022/09/03 10:00:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/garbage.h"

unsigned long long int	tag(void *p)
{
	return ((unsigned long long int)(p) + 1);
}

unsigned long long int	untag(void *p)
{
	return (((unsigned long long int)(p)) - 1);
}

int	tagged(void *p)
{
	return ((unsigned long long int)(p) & 1);
}

void	ft_lstdel(void *content)
{
	free(content);
}
