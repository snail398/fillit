/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:51:07 by lmaximin          #+#    #+#             */
/*   Updated: 2019/12/01 18:54:47 by lmaximin         ###   ########.fr       */
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
