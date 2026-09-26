/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:52:55 by palkhour          #+#    #+#             */
/*   Updated: 2026/01/15 11:11:22 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static char	*get_cwd_value(char *envp[])
{
	char	*cwd;

	cwd = calloc(PATH_MAX, 1);
	getcwd(cwd, PATH_MAX);
	if (get_env("PWD", envp))
	{
		free(cwd);
		cwd = get_env("PWD", envp);
	}
	return (cwd);
}

static char	*build_prompt_prefix(char *cwd, char *envp[])
{
	char	*temp;

	temp = ft_calloc(ft_strlen(cwd) + 29, 1);
	if (!temp)
		return (NULL);
	ft_strlcat(temp, "\033[31mminishell:\033[0m", 26);
	if (get_env("HOME", envp)
		&& ft_strnstr(cwd, get_env("HOME", envp),
			ft_strlen(get_env("HOME", envp))))
	{
		ft_strlcat(temp, "~", 27);
		ft_strlcat(temp,
			&cwd[ft_strlen(get_env("HOME", envp))],
			27 + ft_strlen(&cwd[ft_strlen(get_env("HOME", envp))]));
	}
	else
		ft_strlcat(temp, cwd, 26 + ft_strlen(cwd));
	return (temp);
}

char	*prompt(char *envp[])
{
	char	*cwd;
	char	*temp;
	char	*r;

	cwd = get_cwd_value(envp);
	temp = build_prompt_prefix(cwd, envp);
	if (!temp)
		return (free(cwd), NULL);
	ft_strlcat(temp, "$ ", 3 + ft_strlen(temp));
	r = readline(temp);
	free(temp);
	if (!get_env("PWD", envp))
		free(cwd);
	if (!r)
		return (NULL);
	return (r);
}
