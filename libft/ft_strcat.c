/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:24:45 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/06 20:24:46 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (s1);
}
