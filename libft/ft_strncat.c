/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:33:20 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/06 20:33:21 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2 && n--)
		*temp++ = *s2++;
	*temp = '\0';
	return (s1);
}
