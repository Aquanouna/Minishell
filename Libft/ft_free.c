/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:12:08 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/13 20:12:13 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	cfill(int *s, int *d)
{
	if (*s == 0 && *d == 1)
		*s = 2;
	else if (*s == 0 && *d == 0)
		(*s)++;
	else if (*s == 1 && *d == 2)
	{
		*s = 0;
		*d = 0;
	}
	else if (*s == 1)
		*s = 0;
}

void	fill(t_quotes *q, char c)
{
	if (c == '\'')
		cfill(&q->single, &q->full);
	if (c == '"')
		cfill(&q->full, &q->single);
}

int	check(t_quotes q)
{
	if (q.full == 0 && q.single == 0)
		return (1);
	return (0);
}

void	init(t_quotes *q)
{
	q->single = 0;
	q->full = 0;
}
