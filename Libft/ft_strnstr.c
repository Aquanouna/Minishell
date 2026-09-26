/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:15:40 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/26 18:27:58 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!little[0])
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0] && len - i >= ft_strlen(little))
		{
			if (!ft_strncmp(&big[i], little, ft_strlen(little)))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
