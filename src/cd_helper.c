/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:19:16 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/16 15:19:27 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*tilde(char *s, char *envp[])
{
	t_quotes	q;
	char		*temp;

	init(&q);
	if (s[0] == '~')
	{
		temp = ft_strjoin(getenv("HOME"), &s[1]);
		if (!temp)
			return (NULL);
	}
	else
	{
		temp = ft_strdup(s);
		if (!temp)
			return (NULL);
	}
	free(s);
	temp = cat_arg(temp, q, envp);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*rm_quotes(char *s, char *temp)
{
	int			i;
	int			k;
	t_quotes	q;

	i = 0;
	k = 0;
	init(&q);
	if (!temp)
		temp = s;
	while (s[i])
	{
		fill(&q, s[i]);
		if (s[i] != '\'' && s[i] != '"')
			temp[k++] = s[i];
		else if (s[i] == '\'' && q.single == 2)
			temp[k++] = s[i];
		else if (s[i] == '"' && q.full == 2)
			temp[k++] = s[i];
		i++;
	}
	temp[k] = '\0';
	return (temp);
}
