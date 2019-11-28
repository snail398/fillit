/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:33:08 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/15 18:33:09 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_item(void *content, size_t content_size)
{
	if (content_size)
		ft_memdel(&content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*temp_list;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	temp_list = f(lst);
	if (!(new_list = ft_lstnew(temp_list->content, temp_list->content_size)))
		return (NULL);
	head = new_list;
	lst = lst->next;
	while (lst)
	{
		temp_list = f(lst);
		if (!(new_list->next = ft_lstnew(temp_list->content,
			temp_list->content_size)))
		{
			ft_lstdel(&head, &del_item);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (head);
}
