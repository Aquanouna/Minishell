/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:44:21 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/19 21:19:40 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	if (!s)
		return (s);
	i = 0;
	temp = (unsigned char *) s;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
