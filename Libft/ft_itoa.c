/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:27:57 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/28 21:00:59 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (2);
	if (n == -2147483648)
	{
		count++;
		n = -214748364;
	}
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}

static void	convert(int n, char *res)
{
	int	i;

	i = ft_count(n) - 1;
	res[i--] = 0;
	if (n == 0)
		res[i--] = '0';
	if (n == -2147483648)
	{
		res[i--] = '8';
		n = 214748364;
	}
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (i == 0)
		res[i] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;

	res = malloc(ft_count(n) * sizeof(char));
	if (!res)
		return (0);
	convert(n, res);
	return (res);
}
