/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:58:49 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/11/05 10:39:55 by fbelthoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	slen;
	char	*scpy;

	i = -1;
	slen = 0;
	if (!s)
		return (NULL);
	while (s[slen])
		slen++;
	scpy = malloc (sizeof(*scpy) * (slen + 1));
	if (!scpy)
		return (NULL);
	while (++i < (int)slen)
		scpy[i] = s[i];
	scpy[slen] = '\0';
	return (scpy);
}
