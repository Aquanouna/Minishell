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

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		s;
	char	*r;

	if (!dest || !src)
		return (NULL);
	i = 0;
	s = ft_strlen(dest) + 1;
	r = malloc(s + ft_strlen(src) + 2);
	while (dest[i])
	{
		r[i] = dest[i];
		i++;
	}
	i = 0;
	r[s - 1] = '/';
	while (src[i])
	{
		r[s + i] = src[i];
		i++;
	}
	r[s + i] = '\0';
	return (r);
}
