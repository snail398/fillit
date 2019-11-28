/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:30:56 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/22 17:30:57 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstsize(t_list **alst)
{
	int		count;
	t_list	*list;

	list = *alst;
	count = 0;
	while (list)
	{
		++count;
		list = list->next;
	}
	return (count);
}
