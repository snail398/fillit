/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 07:30:36 by cwing             #+#    #+#             */
/*   Updated: 2020/01/12 09:52:28 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			rotar_map(char **map)
{
	char	*to_end;
	int		iter;

	iter = 0;
	to_end = map[iter];
	while (iter != 3)
	{
		map[iter] = map[iter + 1];
		iter++;
	}
	map[iter] = to_end;
}

void			rotar_str(char **map)
{
	char	to_end;
	int		iter;
	int		jter;

	jter = 0;
	while (jter != 4)
	{
		iter = 0;
		to_end = map[jter][iter];
		while (iter != 3)
		{
			map[jter][iter] = map[jter][iter + 1];
			iter++;
		}
		map[jter][iter] = to_end;
		jter++;
	}
}

int				pillar_empty(char **map)
{
	int		iter;

	iter = 0;
	while (iter < 4)
	{
		if (map[iter][0] == '#')
			return (0);
		iter++;
	}
	return (1);
}

void			up_shape(t_shape *shape)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	shape->width = 0;
	shape->height = 0;
	while (ft_strchr(shape->pos[i], '#'))
	{
		while (shape->pos[i][j])
		{
			if (shape->pos[i][j] == '#')
			{
				if (shape->width <= j)
					shape->width = j + 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	shape->height = i;
}

t_shape			*get_shape(char *buff)
{
	t_shape *shape;

	if (buff == NULL)
		return (NULL);
	if (!(shape = malloc(sizeof(t_shape))))
		return (NULL);
	if ((shape->pos = ft_strsplit(buff, '\n')))
	{
		ft_strdel(&buff);
		while (!(ft_strchr(shape->pos[0], '#')))
			rotar_map(shape->pos);
		while (pillar_empty(shape->pos))
			rotar_str(shape->pos);
		up_shape(shape);
		return (shape);
	}
	else
	{
		ft_memdel((void*)&shape);
		return (NULL);
	}
}
