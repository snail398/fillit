/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:45:26 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/10 18:45:27 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_symbols(int n)
{
	int		res;

	res = n < 0 ? 2 : 1;
	while (n /= 10)
		res++;
	return (res);
}

static void	reverse(char *s)
{
	size_t	size;
	size_t	i;
	char	temp;

	size = ft_strlen(s);
	i = 0;
	while (i < size / 2)
	{
		temp = s[i];
		s[i] = s[size - i - 1];
		s[size - i - 1] = temp;
		++i;
	}
}

static int	check_neg(int *n, char *c, int *i)
{
	if (*n < 0)
	{
		*c = '-';
		*n *= -1;
		*i += 1;
		return (-1);
	}
	return (1);
}

char		*ft_itoa(int n)
{
	char	*temp;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	temp = (char*)malloc(sizeof(char) * (count_symbols(n) + 1));
	if (n == -2147483648)
	{
		ft_strcpy(temp, "-2147483648");
		return (temp);
	}
	if (!temp)
		return (NULL);
	sign = check_neg(&n, temp, &i);
	while (n / 10)
	{
		temp[i++] = (n % 10) + 48;
		n /= 10;
	}
	temp[i] = (n % 10) + 48;
	temp[i + 1] = '\0';
	sign < 0 ? reverse(&temp[1]) : reverse(&temp[0]);
	return (temp);
}
