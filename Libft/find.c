/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:59:49 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/06 10:59:51 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	path_len(char *envp)
{
	int	i;

	if (!envp)
		return (0);
	i = 0;
	while (envp[i] && envp[i] != ':')
		i++;
	return (i);
}

static int	count_paths(char *envp)
{
	int	i;
	int	count;

	if (!envp)
		return (0);
	i = 0;
	count = 0;
	while (envp[i] && envp[i] != ':')
	{
		count++;
		i++;
	}
	return (count);
}

static char	*find_path(t_wh *warehouse)
{
	int	i;

	if (!warehouse->envp)
		return (NULL);
	i = 0;
	while (warehouse->envp[i] && ft_strncmp(warehouse->envp[i], "PATH=", 5))
		i++;
	return (warehouse->envp[i]);
}

char	**get_path(t_wh *warehouse)
{
	int		j;
	int		p;
	char	**paths;
	char	*s;

	if (!warehouse->envp)
		return (NULL);
	s = find_path(warehouse);
	j = 5;
	p = 0;
	paths = malloc((count_paths(s) + 1) * sizeof(char *));
	if (!paths)
		return (NULL);
	while (s[j])
	{
		paths[p] = ft_strndup(&s[j], path_len(&s[j]));
		if (!paths[p])
			return (ft_free(paths), NULL);
		j += path_len(&s[j]);
		if (s[j])
			j++;
		p++;
	}
	paths[p] = NULL;
	return (paths);
}

char	*find(char	*cmd, t_wh *warehouse)
{
	int		i;
	char	**paths;
	char	*temp;

	if (!cmd)
		return (NULL);
	paths = get_path(warehouse);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strcat(paths[i++], cmd);
		if (!access(temp, X_OK))
			return (ft_free(paths), temp);
		free(temp);
	}
	ft_free(paths);
	return (error(cmd, warehouse));
}
