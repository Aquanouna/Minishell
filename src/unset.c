/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:06:52 by palkhour          #+#    #+#             */
/*   Updated: 2026/01/13 15:39:10 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	unset_finde(char *v, char *envp[], int n)
{
	int	i;
	int	len;

	if (!v || !envp)
		return (-1);
	len = ft_strlen(v);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(v, &envp[i][n], len))
		{
			if (envp[i][n + len] == '=' || envp[i][n + len] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}

void	delete_var(char **envp, int i)
{
	int	ind;

	free(envp[i]);
	ind = i;
	while (envp[ind + 1])
	{
		envp[ind] = envp[ind + 1];
		ind++;
	}
	envp[ind] = NULL;
}

void	eunset(char *v, t_wh *warehouse)
{
	int		i;
	char	**env;

	env = warehouse->envp;
	i = unset_finde(v, env, 0);
	if (i == -1)
		return ;
	delete_var(env, i);
}

void	dunset(char *v, t_wh *warehouse)
{
	int		i;
	char	**env;

	env = warehouse->declare_env;
	i = unset_finde(v, env, 11);
	if (i == -1)
		return ;
	delete_var(env, i);
}

void	unset(char **s, t_wh *warehouse)
{
	int			i;
	t_quotes	q;

	i = 0;
	warehouse->exit_status = 0;
	while (s[i])
	{
		init(&q);
		fill(&q, *s[i]);
		s[i] = cat_arg(s[i], q, warehouse->envp);
		eunset(s[i], warehouse);
		dunset(s[i], warehouse);
		i++;
	}
}
