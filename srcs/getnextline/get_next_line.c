/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:17:07 by wmonacho          #+#    #+#             */
/*   Updated: 2022/06/29 17:15:35 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/get_next_line.h"

static char	*ft_line_alloc(char *line, char *buf)
{
	int		j;
	int		i;
	char	*tmp;
	int		k;

	tmp = line;
	j = ft_strlen(buf);
	i = ft_strlen(line);
	line = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!line)
		return (ft_free(tmp));
	j = 0;
	k = 0;
	while (tmp != NULL && tmp[k] != 0)
	{
		line[k] = tmp[k];
		k++;
	}
	while (buf[j] != '\0')
		line[i++] = buf[j++];
	line[i] = '\0';
	free(tmp);
	return (line);
}

static char	*ft_check_line(t_StructBuffer *bufmem, char *buf, char *line)
{
	int		i;
	int		j;
	char	*tmp;
	int		k;

	tmp = line;
	i = ft_strlenn(buf);
	if (i == 0)
		bufmem->redlight = 1;
	j = ft_strlen(line);
	line = (char *)malloc(sizeof(char) * (i + j + 2));
	if (!line)
		return (ft_free(tmp));
	if (i != 0)
		bufmem->index = i + bufmem->index;
	i = -1;
	k = -1;
	while (tmp && tmp[++k] != '\0')
		line[k] = tmp[k];
	while (buf[++i] != '\n' && buf[i] != '\0')
		line[j + i] = buf[i];
	line[j + i] = buf[i];
	line[j + 1 + i] = '\0';
	free(tmp);
	return (line);
}

static char	*ft_readbuffer(int fd, t_StructBuffer *bufmem, int i)
{
	char	*line;

	line = NULL;
	while (i == 0)
	{
		if (ft_strchr(bufmem->buf + bufmem->index, '\n'))
			return (ft_check_line(bufmem, bufmem->buf + bufmem->index, line));
		line = ft_line_alloc(line, bufmem->buf + bufmem->index);
		bufmem->index = 0;
		i = read(fd, bufmem->buf, sizeof(char) * BUFFER_SIZE);
		bufmem->buf[i] = '\0';
		if (i < 0)
			return (ft_free(line));
		if (i == 0)
		{
			if (bufmem->redlight == 1 || ft_strlen(line) == 0)
				return (ft_free(line));
			ft_bzero(bufmem->buf + bufmem->index, BUFFER_SIZE);
			return (ft_check_line(bufmem, bufmem->buf + bufmem->index, line));
		}
		if (ft_strchr(bufmem->buf + bufmem->index, '\n'))
			return (ft_check_line(bufmem, bufmem->buf + bufmem->index, line));
		i = 0;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_StructBuffer	bufmem;
	char					*line;
	int						i;

	if (BUFFER_SIZE == 0)
		return (NULL);
	i = 0;
	line = ft_readbuffer(fd, &bufmem, i);
	if (!line)
	{
		bufmem.buf[0] = 0;
		bufmem.redlight = 0;
	}
	return (line);
}
