/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:23:49 by lmaximin          #+#    #+#             */
/*   Updated: 2019/12/01 19:11:55 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct	s_shape
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_shape;

t_map		*create_default_map(int size);
t_map		*clear_map(t_map *map, int size);
#endif