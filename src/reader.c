/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:26:40 by cwing             #+#    #+#             */
/*   Updated: 2020/01/08 07:18:58 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void        print_contetn(t_shape *shape)
{
	char    **line;
	int     i;

	i = 0;
	line = shape->pos;
	while(i < shape->height)
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

int		check_connection(char *buff)
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

int		check_tetro(char *buff)
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
		else if (buff[i] != '\n')
			return (0);
		i++;
	}
	if (ft_strlen(buff) == 21 && buff[20] != '\n')
		return (0);
	if (!check_connection(buff))
		return (0);
	return (1);
}

char        *read_buff(int fd)
{
	char    *temp;

	if ((temp = ft_strnew(READBUFF)))
	{
		if((read(fd, temp, READBUFF)) && check_tetro(temp))
		{
			return(temp);
		}
		else
		{
			free (temp);
			return(NULL);
		}
	}
	else
		return (NULL);
}

void            rotar_map(char **map)
{
	char    *to_end;
	int     iter;

	iter = 0;    
	to_end = map[iter];
	while(iter != 3)
	{
		map[iter] = map[iter + 1];
		iter++;
	}
	map[iter] = to_end;
}

void            rotar_str(char **map)
{
	char    to_end;
	int     iter;
	int     jter;

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

int             pillar_empty(char **map)
{
	int     iter;

	iter = 0;
	while(iter < 4)
	{
		if (map[iter][0] == '#')
			return (0);
		iter++;
	}
	return (1);
}

void            up_shape(t_shape *shape)
{
	int     i;
	int     j;

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

t_shape         *get_shape(char *buff)
{
	t_shape *shape;

	if (!(shape = malloc(sizeof(t_shape))) || buff == NULL)
		return(NULL);
	if ((shape->pos = ft_strsplit(buff, '\n')))
	{
		while (!(ft_strchr(shape->pos[0],'#')))
			rotar_map(shape->pos);
		while (pillar_empty(shape->pos))
			rotar_str(shape->pos);
		up_shape(shape);
		return(shape);
	}
	else
	{
		free(shape);
		return(NULL);
	}
}

static char	**clean_arr(char **res)
{
	int		i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	res = NULL;
	return (NULL);
}


void        ft_lstfree(t_list **list)
{
	t_list  *to_del;
	t_list  *next;
	t_shape *del_shape;

	to_del = *list;
	while (to_del)
	{
		next = to_del->next;
		del_shape = to_del->content;
		clean_arr(del_shape->pos);
		free(del_shape);
		del_shape = NULL;
		free(to_del);
		to_del = next;
	}
	list = NULL;
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
	while(start)
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
	t_list  *list;
	t_list  *t_lst;
	char    *temp;

	list = NULL;
	while ((temp = read_buff(fd)))
	{
		if ((list == NULL) && (list = ft_lstnew(get_shape(temp), sizeof(t_shape) + 1)))
			continue;
		else if ((t_lst = ft_lstnew(get_shape(temp), sizeof(t_shape) + 1)))
			ft_lstaddtoend(&list,t_lst);
		else
		{
			ft_lstfree(&list);
			ft_strdel(&temp);
			return(NULL);
		}
	}
	set_val(list);
	delete_fat(list);
	if (read(fd, 0 ,1))
	{
		ft_lstfree(&list);
		return(NULL);
	}
	return(list);
}
