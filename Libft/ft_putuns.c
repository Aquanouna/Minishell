/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <ndahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:10:15 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/24 16:23:18 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	countuns(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

int	ft_putuns(int fd, unsigned int n)
{
	char	*tab;
	char	*base;
	int		i;
	int		r;

	base = "0123456789";
	i = 0;
	r = 0;
	tab = malloc(countuns(n));
	if (!tab)
		return (0);
	while (n >= 10)
	{
		tab[i] = base[n % 10];
		i++;
		n = n / 10;
	}
	tab[i++] = base[n];
	while (i-- > 0)
		r += ft_putchar(fd, tab[i]);
	free(tab);
	return (r);
}
