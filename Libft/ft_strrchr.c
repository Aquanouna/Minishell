/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:54:41 by ndahouk           #+#    #+#             */
/*   Updated: 2025/05/21 21:03:00 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last = (char *) &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (last);
}
