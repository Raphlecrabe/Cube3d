/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:57:44 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 13:35:40 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = -1;
	p = NULL;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == (char)c)
			p = (char *)&s[i];
	if (c == '\0')
		p = (char *)&s[i];
	return (p);
}
