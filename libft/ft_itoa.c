/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:38:39 by fbelthoi          #+#    #+#             */
/*   Updated: 2021/09/30 14:18:13 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nlen(long int n)
{
	int	i;

	i = 0;
	while (++i && n >= 10)
		n /= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	ln;
	int			i;
	int			len;
	int			isneg;

	ln = n;
	isneg = (ln < 0);
	if (isneg)
		ln = -ln;
	len = ft_nlen(ln);
	str = malloc (sizeof(*str) * (len + isneg + 1));
	if (!str)
		return (NULL);
	if (isneg)
		str[0] = '-';
	i = len + isneg;
	while (--i >= isneg)
	{
		str[i] = '0' + (ln % 10);
		ln /= 10;
	}
	str[len + isneg] = '\0';
	return (str);
}
