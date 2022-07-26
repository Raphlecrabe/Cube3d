/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:12:25 by rmonacho          #+#    #+#             */
/*   Updated: 2022/07/21 17:12:25 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdlib.h>
# include "../libft/libft.h"

# define TAG(p) ((unsigned long long int) (p) + 1)
# define UNTAG(p) (((unsigned long long int) (p)) - 1)
# define TAGGED(p) (((unsigned long long int) (p) & 1))

typedef struct s_memory
{
	t_list	*used;
}				t_memory;

void	*ft_malloc_const(size_t memory, size_t size, t_memory *mem);
void	*ft_malloc_temp(size_t memory, size_t size, t_memory *mem);
void	ft_freemem(t_memory *mem);
void	ft_freetemp(t_memory *mem);
char	*ft_strncopy_const(char *line, int n, char c, t_memory *mem);
t_list	*ft_lstnew_temp(void *content, t_memory *mem);
char	**ft_split_temp(char const *s, char c, t_memory *mem);

#endif