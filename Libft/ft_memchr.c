/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:55:17 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/26 16:36:20 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	c = (unsigned char) c;
	temp = (unsigned char *) s;
	while (i < n)
	{
		if (temp[i] == c)
			return (&temp[i]);
		i++;
	}
	return (0);
}
