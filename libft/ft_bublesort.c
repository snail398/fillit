/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bublesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:55:06 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/17 19:55:08 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bublesort(int *arr, int size)
{
	int j;
	int i;
	int flag;

	j = 0;
	while (j <= size - 1)
	{
		flag = 0;
		i = 0;
		while (i < size - j)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap_int(&arr[i], &arr[i + 1]);
				flag = 1;
			}
			++i;
		}
		if (flag == 0)
			break ;
		++j;
	}
}
