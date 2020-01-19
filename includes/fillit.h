/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:23:49 by lmaximin          #+#    #+#             */
/*   Updated: 2020/01/19 17:31:01 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# define READBUFF 21

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

void			print_map(t_map *map);
t_map			*create_default_map(int size);
t_map			*clear_map(t_map *map, int size);
int				try_place_shape(t_shape *shape, t_map *map, t_point *p);
void			place_shape(t_shape *shape, t_map *map, t_point *p, char c);
t_point			*create_point(int x, int y);
t_list			*read_input_file(int fd);
t_shape			*get_shape(char *buff);
void			ft_lstfree(t_list **list);
int				check_tetro(char *buff);
t_map			*solve(t_list *list);
void			print_contetn(t_shape *shape);
void			*clear_temp(t_list *list, char *temp, t_shape *t_shp);
t_list			*last_check(t_list *list, char *temp, t_shape *t_shp, int d);
void			set_val(t_list *head2);
void			delete_fat(t_list *head);

#endif
