/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:39:13 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/21 14:39:15 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_first(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_last(char *s, char c)
{
	int	i;
	int	f;
	int	l;

	i = 0;
	l = -1;
	f = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (l == -1)
				l = i;
			else
			{
				f = l;
				l = i;
			}
		}
		i++;
	}
	if (f == -1)
		f = l;
	return (f);
}

int	first_int(int *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
