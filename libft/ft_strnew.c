/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:44:26 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/08 19:44:27 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (size == SIZE_MAX)
		return (NULL);
	mem = (char*)malloc(sizeof(*mem) * (size + 1));
	if (!mem)
		return (NULL);
	ft_memset(mem, '\0', size + 1);
	return (mem);
}
