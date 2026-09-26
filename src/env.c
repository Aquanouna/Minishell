/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:31:03 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/16 16:31:17 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*get_env(char *s, char *envp[])
{
	int	i;
	int	len;

	i = 0;
	while (envp[i])
	{
		len = ft_strlen(s);
		if (!ft_strncmp(envp[i], s, len))
		{
			if (envp[i][len] == '=')
				return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

void	print(char *s[])
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

void	env(t_wh *warehouse)
{
	print(warehouse->envp);
	warehouse->exit_status = 0;
}
