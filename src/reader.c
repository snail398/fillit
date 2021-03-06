/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:26:40 by cwing             #+#    #+#             */
/*   Updated: 2020/01/19 17:29:54 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		print_contetn(t_shape *shape)
{
	char	**line;
	int		i;

	i = 0;
	line = shape->pos;
	while (i < shape->height)
	{
		ft_putstr(line[i]);
		i++;
		ft_putchar('\n');
	}
	ft_putstr("Height: ");
	ft_putchar(shape->height + 48);
	ft_putstr(" weight: ");
	ft_putchar((char)shape->width + 48);
	ft_putstr(" value: ");
	ft_putchar(shape->value);
	ft_putchar('\n');
	ft_putchar('\n');
}

char		*read_buff(int fd)
{
	char	*temp;

	if ((temp = ft_strnew(READBUFF)))
	{
		if ((read(fd, temp, READBUFF)))
			return (temp);
		else
		{
			free(temp);
			return (NULL);
		}
	}
	else
		return (NULL);
}

void		set_val(t_list *head2)
{
	char	alpha;
	t_shape	*shape;
	t_list	*head;

	if (head2 == NULL)
		return ;
	head = head2;
	alpha = 'A';
	while (head)
	{
		shape = (t_shape*)head->content;
		shape->value = alpha++;
		head = head->next;
	}
}

void		delete_fat(t_list *head)
{
	t_list	*start;
	t_shape	*shape;
	int		y;

	start = head;
	y = 0;
	while (start)
	{
		shape = start->content;
		while (shape->pos[y])
		{
			if (y < shape->height)
				shape->pos[y][shape->width] = '\0';
			else
			{
				free(shape->pos[y]);
				shape->pos[y] = NULL;
			}
			y++;
		}
		y = 0;
		start = start->next;
	}
}

t_list		*read_input_file(int fd)
{
	t_list	*list;
	t_list	*t_lst;
	char	*temp;
	t_shape	*t_shp;
	int		check;

	list = NULL;
	while ((temp = read_buff(fd)))
	{
		check = ft_strlen(temp);
		t_shp = NULL;
		if (!check_tetro(temp))
			return (clear_temp(list, temp, t_shp));
		if (!(t_shp = get_shape(temp)))
			return (clear_temp(list, temp, t_shp));
		if (!(t_lst = ft_lstnew(t_shp, sizeof(t_shape))))
			return (clear_temp(list, temp, t_shp));
		ft_memdel((void*)&t_shp);
		if (list == NULL)
			list = t_lst;
		else
			ft_lstaddtoend(&list, t_lst);
	}
	return (last_check(list, temp, t_shp, check));
}
