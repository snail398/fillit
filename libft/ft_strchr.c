/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:17:10 by lmaximin          #+#    #+#             */
/*   Updated: 2019/12/23 22:27:13 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (s == NULL)
		return(NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		++i;
	return (c == s[i] ? (char*)s + i : NULL);
}
