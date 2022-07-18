/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:10:35 by wmonacho          #+#    #+#             */
/*   Updated: 2022/07/18 11:12:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_StructBuffer
{
	size_t	redlight;
	size_t	index;
	char	buf[BUFFER_SIZE];
}	t_StructBuffer;

char	*get_next_line(int fd);
char	*ft_free(char *freestr);
//char	*ft_strchr(char *string, int searchedChar);
//int		ft_strlen(char *str);
int		ft_strlenn(char *str);
//void	ft_bzero(void *s, size_t n);

#endif