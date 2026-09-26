/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:55:22 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/24 17:58:30 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstr(int fd, char *s)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (!s)
		return (ft_putstr(fd, "(null)"));
	while (s[i])
	{
		r += ft_putchar(fd, s[i]);
		i++;
	}
	return (r);
}
