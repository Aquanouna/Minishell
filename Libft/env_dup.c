/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:44:43 by ndahouk           #+#    #+#             */
/*   Updated: 2026/02/02 12:44:55 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	**env_dup(char *envp[], int n)
{
	int		i;
	int		len;
	char	**res;

	i = 0;
	len = count(envp) + n;
	res = ft_calloc(len, sizeof(char *));
	if (!res)
		return (NULL);
	while (envp[i] && i < count(envp) + n - 1)
	{
		res[i] = ft_strdup(envp[i]);
		if (!res[i])
			return (ft_free(res), NULL);
		i++;
	}
	if (n < 0)
		res[i] = NULL;
	return (res);
}
