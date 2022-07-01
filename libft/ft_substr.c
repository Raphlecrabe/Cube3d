/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:20:33 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 13:45:02 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		slen;
	int		i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((int)len > slen)
		len = slen;
	sub = malloc (sizeof(*sub) * (len + 1));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < (int)len && (int)start + i < slen && s[start + i] != 0)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
