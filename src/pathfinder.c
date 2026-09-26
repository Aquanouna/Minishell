/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:32:23 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/23 14:32:33 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*handle_dots(char *p, int *i, char *temp)
{
	char	*t;
	int		last;

	if (p[*i] == '.' && (!p[*i + 1] || p[*i + 1] == '.' || p[*i + 1] == '/'))
	{
		(*i)++;
		if (p[*i] && p[*i] == '.' && (p[*i + 1] == '/' || !p[*i + 1]))
		{
			t = temp;
			last = ft_last(temp, '/');
			if (last >= 0)
			{
				if (last == 0)
					last++;
				temp = ft_substr(temp, 0, last);
				if (!temp)
					return (NULL);
				free(t);
			}
			(*i)++;
		}
	}
	return (temp);
}

char	*handle_rest(char *p, int *i, char *temp)
{
	char	*t;
	char	*s;

	s = &p[*i];
	if (ft_first(s, '/') >= 0)
	{
		s = ft_substr(s, 0, ft_first(s, '/') + 1);
		if (!s)
			return (NULL);
	}
	else
	{
		s = ft_strdup(&p[*i]);
		if (!s)
			return (NULL);
	}
	t = temp;
	temp = ft_strjoin(temp, s);
	if (!temp)
		return (NULL);
	*i += ft_strlen(s);
	free(s);
	free(t);
	return (temp);
}

char	*fullpath(char *p, char *here)
{
	char	*temp;
	int		i;

	if (p[0] == '/')
		return (ft_strdup(p));
	i = 0;
	temp = ft_strjoin(here, "/");
	while (p[i])
	{
		temp = handle_dots(p, &i, temp);
		if (!p[i])
			break ;
		temp = handle_rest(p, &i, temp);
	}
	if (ft_strlen(temp) > 1 && temp[ft_strlen(temp) - 1] == '/')
		temp[ft_strlen(temp) - 1] = '\0';
	return (temp);
}
