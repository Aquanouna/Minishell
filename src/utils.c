/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:47:48 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/12 12:47:54 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	shell(t_wh *warehouse)
{
	int		i;
	int		l;
	char	*temp;

	warehouse->envp = env_dup(warehouse->envp, 1);
	if (!warehouse->envp)
		return (0);
	i = finde("SHLVL", warehouse->envp, 0);
	l = ft_strlen ((warehouse->envp)[i]) + 2;
	temp = ft_itoa(ft_atoi(getenv("SHLVL")) + 1);
	ft_strlcpy((warehouse->envp)[i], "SHLVL=", l);
	if (!temp)
		return (ft_free(warehouse->envp), 0);
	ft_strlcat((warehouse->envp)[i], temp, l);
	free(temp);
	warehouse->declare_env = declare(warehouse->envp, 1);
	if (!warehouse->declare_env)
		return (free(warehouse->envp), 0);
	return (1);
}

char	*parse(char *s)
{
	int		i;
	int		len;
	char	*v;

	i = 0;
	len = checkv(s);
	if (!len)
		return (NULL);
	v = malloc(len + 1);
	if (!v)
		return (NULL);
	while (s[i] && s[i] != '=')
	{
		v[i] = s[i];
		i++;
	}
	v[i] = 0;
	return (v);
}
