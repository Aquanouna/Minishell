/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:49:41 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/14 09:49:43 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	finde(char *v, char *envp[], int n)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(v, &envp[i][n], ft_strlen(v)))
		{
			if (envp[i][n + ft_strlen(v)] == '=' || !envp[i][n + ft_strlen(v)])
				return (i);
		}
		i++;
	}
	return (i);
}

char	*get_d(char *s, char *envp[])
{
	int	i;
	int	len;

	i = 0;
	while (envp[i])
	{
		len = ft_strlen(s);
		if (!ft_strncmp(&envp[i][11], s, len))
		{
			if (envp[i][11 + len] == '=' || !envp[i][11 + len])
				return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

void	dexport(char *v, char *s, t_wh *warehouse, int c)
{
	char		**d;
	int			f;

	f = finde(v, warehouse->declare_env, 11);
	d = warehouse->declare_env;
	if (!get_d(v, warehouse->declare_env))
	{
		d = env_dup(warehouse->declare_env, 2);
		if (!d)
			return ;
		ft_free(warehouse->declare_env);
		d[f] = ft_join("declare -x ", s);
		if (!d[f])
			return ;
		warehouse->declare_env = d;
		return ;
	}
	else if (c)
	{
		free(d[f]);
		d[f] = ft_join("declare -x ", s);
		if (!d[f])
			return ;
		warehouse->declare_env = d;
	}
}

void	eexport(char *v, char *s, t_wh *warehouse)
{
	int		j;
	char	**t;

	j = finde(v, warehouse->envp, 0);
	t = warehouse->envp;
	if (!get_env(v, warehouse->envp))
	{
		t = env_dup(warehouse->envp, 2);
		if (!t)
			return ;
		ft_free(warehouse->envp);
	}
	else
		free(t[j]);
	t[j] = ft_strdup(s);
	if (!t[j])
		return ;
	warehouse->envp = t;
}

void	e_help(char *s, t_wh *warehouse)
{
	char		*v;

	if (checkv(s) != -1)
	{
		v = parse(s);
		if (!v)
		{
			warehouse->exit_status = 1;
			ft_printf(2, "minishell: export: %s: not a valid identifier\n", s);
		}
		else
		{
			eexport(v, s, warehouse);
			dexport(v, s, warehouse, 1);
			free(v);
		}
	}
	else
		dexport(s, s, warehouse, 0);
}
