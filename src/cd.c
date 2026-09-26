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

void	update_env(char *s, t_wh *warehouse)
{
	char	*temp;
	char	*ptemp;

	free(warehouse->pwd);
	warehouse->pwd = ft_strdup(s);
	ptemp = get_env("PWD", warehouse->envp);
	if (!ptemp)
		ptemp = "";
	temp = ft_strjoin("OLDPWD=", ptemp);
	eexport("OLDPWD", temp, warehouse);
	free(temp);
	temp = ft_join("OLDPWD=", ptemp);
	dexport("OLDPWD", temp, warehouse, 1);
	free(temp);
	temp = ft_strjoin("PWD=", warehouse->pwd);
	eexport("PWD", temp, warehouse);
	free(temp);
	temp = ft_join("PWD=", warehouse->pwd);
	dexport("PWD", temp, warehouse, 1);
	free(temp);
}

void	cd_help(char **s, t_wh *warehouse)
{
	char		*path;

	*s = tilde(*s, warehouse->envp);
	if (chdir(rm_quotes(*s, NULL)) == -1)
	{
		ft_printf(2, "minishell: cd: %s: %s\n", rm_quotes(*s, NULL),
			strerror(errno));
		warehouse->exit_status = 1;
	}
	else
	{
		path = get_env("PWD", warehouse->envp);
		if (!path)
			path = &warehouse->pwd[1];
		path = fullpath(*s, path);
		if (!path)
			return ;
		update_env(path, warehouse);
		free(path);
	}
}

void	handle_cd_home(char **s, t_wh *warehouse)
{
	char	*home;

	home = get_env("HOME", warehouse->envp);
	if (!home)
	{
		if (!s[0])
		{
			ft_printf(2, "minishell: cd: HOME not set\n");
			warehouse->exit_status = 1;
			return ;
		}
		home = getenv("HOME");
	}
	if (chdir(home) == -1)
	{
		ft_printf(2, "minishell: cd: %s %s\n", home, strerror(errno));
		warehouse->exit_status = 1;
	}
	else
		update_env(home, warehouse);
}

int	handle_cd_args(char **s, t_wh *warehouse)
{
	if (s[0] && s[1])
	{
		warehouse->exit_status = 1;
		ft_printf(2, "minishell: cd : too many arguments\n");
		return (1);
	}
	return (0);
}

void	cd(char **s, t_wh *warehouse)
{
	warehouse->exit_status = 0;
	if (handle_cd_args(s, warehouse))
		return ;
	else if (!s[0] || !ft_strcmp(s[0], "~"))
		handle_cd_home(s, warehouse);
	else
		cd_help(&s[0], warehouse);
}
