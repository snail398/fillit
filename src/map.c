/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:58:03 by lmaximin          #+#    #+#             */
/*   Updated: 2019/12/01 18:54:27 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

t_map		*clear_map(t_map *map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
	return (NULL);
}

t_map		*create_default_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->array = (char**)ft_memalloc(sizeof(char*) * (size))))
		return (clear_map(map, 0));
	i = 0;
	while (i < size)
	{
		if (!(map->array[i] = ft_strnew(size)))
			return (clear_map(map, i));
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

int			try_place_shape(t_shape *shape, t_map *map, t_point *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < shape->width)
	{
		j = 0;
		while (j < shape->height)
		{
			if (shape->pos[j][i] == '#'
				&& map->array[j + p->y][i + p->x] != '.')
			{
				ft_memdel((void**)&p);
				return (0);
			}
			j++;
		}
		i++;
	}
	place_shape(shape, map, p, shape->value);
	return (1);
}

void		place_shape(t_shape *shape, t_map *map, t_point *p, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < shape->width)
	{
		j = 0;
		while (j < shape->height)
		{
			if (shape->pos[j][i] == '#')
				map->array[j + p->y][i + p->x] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&p);
}
