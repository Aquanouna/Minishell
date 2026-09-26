/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:14:48 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/24 18:39:03 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

int	ft_putn(int fd, int n)
{
	int		i;
	int		r;
	char	*tab;

	i = 0;
	r = 0;
	tab = malloc(ft_count(n));
	if (n < 0)
	{
		n = -n;
		r += ft_putchar(fd, '-');
	}
	while (n > 0)
	{
		tab[i++] = n % 10 + '0';
		n = n / 10;
	}
	while (i-- > 0)
		r += ft_putchar(fd, tab[i]);
	free(tab);
	return (r);
}

int	ft_putnbr(int fd, int n)
{
	int		r;

	r = 0;
	if (n == 0)
		r += ft_putchar(fd, '0');
	else if (n == -2147483648)
		r += ft_putstr(fd, "-2147483648");
	else
		r += ft_putn(fd, n);
	return (r);
}
