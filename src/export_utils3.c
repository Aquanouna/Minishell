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

char	*handle_dol_ex(char *s, int *i, int exit_status, char *envp[])
{
	int		j;
	char	*temp;
	char	*e;

	j = 1;
	if (s[*i + 1] && s[*i + 1] == '?')
	{
		(*i)++;
		return (ft_itoa(exit_status));
	}
	if (!ft_isalpha(s[*i + j]))
		return ((*i)++, ft_strdup(""));
	while (s[*i + j] && !ft_isspace(s[*i + j]) && ft_isalnum(s[*i + j]))
		j++;
	temp = ft_substr(s, *i + 1, j - 1);
	*i += j - 1;
	e = get_env(temp, envp);
	free(temp);
	if (e)
		return (ft_strdup(e));
	return (ft_strdup(""));
}
