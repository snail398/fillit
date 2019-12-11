/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:26:40 by cwing             #+#    #+#             */
/*   Updated: 2019/12/11 21:35:59 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char        *read_buff(int fd)
{
    char    *temp;

    if ((temp = ft_strnew(READBUFF)))
    {
        if((read(fd, temp, READBUFF)))
            return(temp);
        else
        {
            ft_strdel(&temp);
            return(NULL);
        }
    }
    else
        return (NULL);
}

void        ft_lstfree(t_list **list)
{
    t_list  *todel;

    todel = *list;
    while (todel)
    {
        *list = todel->next;
        free(todel->content);
        todel->content_size = 0;
        todel->next = NULL;
        todel = *list;
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
        if ((list == NULL) && (list = ft_lstnew(temp, READBUFF)))
            continue;
        else if ((t_lst = ft_lstnew(temp, READBUFF)))
            ft_lstaddtoend(&list,t_lst);
        else
        {
            ft_lstfree(&list);
            return(NULL);
        }
    }
    return(list);
}
int main(int argc, char **argv)
{
    int     fd;
    char    *tetro;
    t_list  *list;

    if (argc == 1)
        ft_putstr("Filit usage file.\n");
    else if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        list = read_input_file(fd);
        while (list)
        {
            ft_putstr(list->content);
            list = list->next;
        }
    }
    ft_putchar('\n');
    return(0);
}