/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:51:07 by lmaximin          #+#    #+#             */
/*   Updated: 2020/01/12 09:57:35 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

t_point			*create_point(int x, int y)
{
	t_point		*p;

	p = (t_point*)ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

static int		check_connection(char *buff)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			if ((i + 1) < 20 && buff[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && buff[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && buff[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && buff[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int				check_tetro(char *buff)
{
	int		i;
	int		line;

	i = 0;
	line = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(buff[i] == '#' || buff[i] == '.'))
				return (0);
			if (buff[i] == '#' && ++line > 4)
				return (0);
		}
		else if (buff[i] != '\n' && ft_strlen(buff) > 19)
			return (0);
		i++;
	}
	if (ft_strlen(buff) == 21 && buff[20] != '\n')
		return (0);
	if (!check_connection(buff))
		return (0);
	return (1);
}

static char		**clean_arr(char **res)
{
	int		i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	res = NULL;
	return (NULL);
}

void			ft_lstfree(t_list **list)
{
	t_list	*to_del;
	t_list	*next;
	t_shape	*del_shape;

	to_del = *list;
	while (to_del)
	{
		next = to_del->next;
		del_shape = (t_shape*)to_del->content;
		clean_arr(del_shape->pos);
		ft_memdel((void*)&del_shape);
		ft_memdel((void*)&to_del);
		to_del = next;
	}
	list = NULL;
}
