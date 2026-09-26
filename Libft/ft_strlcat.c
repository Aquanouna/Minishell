/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:54:21 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/21 19:58:34 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sd;
	size_t	ss;

	i = 0;
	sd = 0;
	ss = 0;
	while (dest[sd] && sd < size)
		sd++;
	while (src[ss])
		ss++;
	if (size == 0)
		return (ss);
	if (sd >= size)
		return (size + ss);
	while (src[i] && i < size - sd - 1)
	{
		dest[sd + i] = src[i];
		i++;
	}
	dest[sd + i] = '\0';
	return (sd + ss);
}
