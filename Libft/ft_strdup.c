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

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*temp;

	size = 0;
	while (src[size])
		size++;
	temp = malloc((size + 1) * sizeof(char));
	if (! temp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
