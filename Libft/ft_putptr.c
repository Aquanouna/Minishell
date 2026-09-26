/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <ndahouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:02:35 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/24 18:38:41 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count(void *ptr)
{
	size_t		i;
	uintptr_t	n;

	i = 0;
	n = (uintptr_t) ptr;
	while (n >= 16)
	{
		i++;
		n = n / 16;
	}
	return (i + 1);
}

static int	ft_putp(int fd, uintptr_t n, void *ptr, char *base)
{
	int		i;
	char	*tab;
	int		r;

	i = 0;
	r = 0;
	tab = malloc(ft_count(ptr));
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

int	ft_putptr(int fd, void *ptr)
{
	uintptr_t	n;
	char		*base;
	int			r;

	base = "0123456789abcdef";
	n = (uintptr_t) ptr;
	if (!n)
		return (ft_putstr(fd, "(nil)"));
	r = 0;
	r += ft_putstr(fd, "0x");
	r += ft_putp(fd, n, ptr, base);
	return (r);
}
