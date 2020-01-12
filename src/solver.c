/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:04:55 by lmaximin          #+#    #+#             */
/*   Updated: 2020/01/12 10:34:25 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_shape		*shape;

	if (list == NULL)
		return (1);
	y = 0;
	shape = (t_shape*)list->content;
	while (y < map->size - shape->height + 1)
	{
		x = 0;
		while (x < map->size - shape->width + 1)
		{
			if (try_place_shape(shape, map, create_point(x, y)))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					place_shape(shape, map, create_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			get_min_size(int shape_count)
{
	int		size;

	size = 1;
	while (size * size < shape_count * 4)
		size++;
	return (size);
}

t_map		*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = get_min_size(ft_lstsize(&list));
	map = create_default_map(size);
	while (!solve_map(map, list))
	{
		size++;
		clear_map(map, map->size);
		map = create_default_map(size);
	}
	return (map);
}

void		*clear_temp(t_list *list, char *temp, t_shape *t_shp)
{
	ft_memdel((void*)&t_shp);
	ft_lstfree(&list);
	ft_strdel(&temp);
	return (NULL);
}
