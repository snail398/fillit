/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:04:55 by lmaximin          #+#    #+#             */
/*   Updated: 2019/12/01 19:13:21 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			solve_map(t_map *map, t_shape *shape)
{
	
}

int			get_min_size(int	shape_count)
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
