/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelitem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:03 by lmaximin          #+#    #+#             */
/*   Updated: 2019/10/07 20:32:04 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelitem(t_list **alst, t_list *item)
{
	t_list		*list;
	t_list		*prev_item;

	list = *alst;
	prev_item = *alst;
	if (prev_item == item)
	{
		*alst = prev_item->next;
		free(item);
		item = NULL;
		return ;
	}
	list = list->next;
	while (list)
	{
		if (list == item)
		{
			prev_item->next = list->next;
			free(item);
			item = NULL;
			return ;
		}
		prev_item = list;
		list = list->next;
	}
}
