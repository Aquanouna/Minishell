/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:45:37 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/10 22:55:41 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 3, 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	i = ft_strlen(s1);
	j = 0;
	while (s2[j] && s2[j] != '=')
		res[i++] = s2[j++];
	if (s2[j])
	{
		res[i++] = s2[j++];
		res[i++] = '"';
		while (s2[j])
		{
			res[i] = s2[j];
			i++;
			j++;
		}
		res[i++] = '"';
	}
	return (res);
}
