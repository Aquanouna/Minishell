/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <ndahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:42:55 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/24 16:56:59 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	counthex(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n >= 16)
	{
		i++;
		n = n / 16;
	}
	return (i + 1);
}

int	ft_puthex(int fd, unsigned int n, int c)
{
	char	*tab;
	char	*base;
	int		i;
	int		r;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	r = 0;
	tab = malloc(counthex(n));
	if (!tab)
		return (0);
	while (n >= 16)
	{
		tab[i] = base[n % 16];
		i++;
		n = n / 16;
	}
	tab[i++] = base[n];
	while (i-- > 0)
		r += ft_putchar(fd, tab[i]);
	free(tab);
	return (r);
}
