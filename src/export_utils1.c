/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:30:41 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/12 13:30:54 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*helper_checkv(char *s, t_quotes q, int *i, char **envp)
{
	char	*str;

	str = NULL;
	if (q.full == 1 && s[*i] == '$' && s[*i + 1] && !ft_isspace(s[*i + 1])
		&& (s[*i + 1] == '?' || ft_isalnum(s[*i + 1])))
		str = handle_dol_ex(s, i, 0, envp);
	else if (check(q) && s[*i] == '$' && s[*i + 1] && !ft_isspace(s[*i + 1])
		&& (ft_isalnum(s[*i + 1]) || s[*i + 1] == '?' || s[*i + 1] == '"'))
		str = handle_dol_ex(s, i, 0, envp);
	return (str);
}

char	*cat_help(char *temp, char *str)
{
	char	*new;

	new = ft_strjoin(temp, str);
	if (!new)
		return (NULL);
	free(temp);
	free(str);
	return (new);
}

char	*cat_arg(char *s, t_quotes q, char **envp)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup("");
	while (s[i])
	{
		fill(&q, s[i]);
		str = helper_checkv(s, q, &i, envp);
		if (str)
			temp = cat_help(temp, str);
		else
		{
			if (!((s[i] == '\'' && q.single != 2)
					|| (s[i] == '"' && q.full != 2)))
			{
				str = ft_substr(s, i, 1);
				temp = cat_help(temp, str);
			}
		}
		i++;
	}
	free(s);
	return (temp);
}

char	*cat_arg_wq(char *s, t_quotes q, char **envp)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup("");
	while (s[i])
	{
		fill(&q, s[i]);
		str = helper_checkv(s, q, &i, envp);
		if (str)
			temp = cat_help(temp, str);
		else
		{
			str = ft_substr(s, i, 1);
			temp = cat_help(temp, str);
		}
		i++;
	}
	free(s);
	return (temp);
}

int	checkv(char *s)
{
	int	i;

	i = 0;
	if (!ft_isalpha(s[i]) && s[i] != '_')
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	if (i > 0 && s[i] != '=')
		return (-1);
	return (i);
}
