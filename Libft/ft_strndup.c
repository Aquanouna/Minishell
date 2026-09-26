/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:20:16 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/26 21:43:54 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	size_t	size;
	char	*temp;

	size = ft_strlen(src);
	if (size > n)
		size = n;
	temp = malloc((size + 1) * sizeof(char));
	if (! temp)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
