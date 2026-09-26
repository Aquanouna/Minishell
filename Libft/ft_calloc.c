/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:04:28 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/26 21:18:37 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (0);
	temp = malloc(nmemb * size);
	if (!temp)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
