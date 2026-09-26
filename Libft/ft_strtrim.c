/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:01:38 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/10 21:07:41 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	k;
	size_t	size;

	if (!s1 || !set)
		return (0);
	size = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (size > i && ft_strchr(set, s1[size - 1]))
		size--;
	res = malloc ((size - i + 1) * sizeof(char));
	if (!res)
		return (0);
	k = 0;
	while (i < size)
	{
		res[k] = s1[i];
		i++;
		k++;
	}
	res[k] = 0;
	return (res);
}
