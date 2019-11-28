/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:45:40 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/06 19:45:42 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	char	*start;

	temp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!temp)
		return (NULL);
	start = temp;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (start);
}
