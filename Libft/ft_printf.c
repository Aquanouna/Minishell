/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:37:35 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/24 16:23:43 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_convert(int fd, va_list args, int c)
{
	int	r;

	r = 0;
	if (c == '%')
		r += ft_putchar(fd, c);
	else if (c == 'c')
		r += ft_putchar(fd, va_arg(args, int));
	else if (c == 's')
		r += ft_putstr(fd, va_arg(args, char *));
	else if (c == 'p')
		r += ft_putptr(fd, va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		r += ft_putnbr(fd, va_arg(args, int));
	else if (c == 'u')
		r += ft_putuns(fd, va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		r += ft_puthex(fd, va_arg(args, unsigned int), c);
	return (r);
}

int	ft_printf(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		r;

	va_start(args, s);
	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			r += ft_convert(fd, args, s[i]);
			i++;
		}
		else
			r += ft_putchar(fd, s[i++]);
	}
	va_end(args);
	return (r);
}
