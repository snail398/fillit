/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:10:00 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/08 20:10:01 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (len--)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
