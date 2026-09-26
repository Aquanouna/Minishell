/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:16:51 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/13 17:16:53 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	clean(char **r, t_wh *warehouse)
{
	int			i;
	t_quotes	q;

	init(&q);
	i = 0;
	while (r[i])
	{
		r[i] = cat_arg(r[i], q, warehouse->envp);
		i++;
	}
}

int	exit_arg(char **s)
{
	int	i;
	int	j;

	i = 0;
	printf("exit\n");
	if (!s[0])
		return (0);
	if (s[0] && s[1])
		return (ft_printf(2, "minishell: exit: too many arguments\n"), 1);
	rm_quotes(s[0], NULL);
	if (*s[0] == '-' || *s[0] == '+')
	{
		if (*s[0] == '-')
			return (156);
		i++;
	}
	while (s[0][i])
	{
		if (!ft_isdigit(s[0][i]))
			return (ft_printf(2, "minishell: exit: %s: ", s[0]),
				ft_printf(2, "numeric argument required\n"), 2);
		i++;
	}
	j = ft_atoi(s[0]);
	return (j % 256);
}

int	mini_exec(char **r, t_wh *warehouse)
{
	int	e;

	if (!ft_strcmp(rm_quotes(r[0], NULL), "echo"))
		return (echo(&r[1], warehouse), 1);
	if (!ft_strcmp(rm_quotes(r[0], NULL), "cd"))
		return (cd(&r[1], warehouse), 1);
	if (!ft_strcmp(rm_quotes(r[0], NULL), "pwd"))
		return (pwd(warehouse), 1);
	if (!ft_strcmp(rm_quotes(r[0], NULL), "env"))
		return (env(warehouse), 1);
	if (!ft_strcmp(rm_quotes(r[0], NULL), "export"))
		return (export(&r[1], warehouse), 1);
	if (!ft_strcmp(rm_quotes(r[0], NULL), "unset"))
		return (unset(&r[1], warehouse), 1);
	if (!ft_strcmp(rm_quotes(r[0], NULL), "exit"))
	{
		e = exit_arg(&r[1]);
		return (ft_free(r), ft_free(warehouse->envp),
			ft_free(warehouse->declare_env), rl_clear_history(), exit(e), 0);
	}
	return (-1);
}

int	checkr(char ***r, t_wh *warehouse)
{
	t_quotes	q;
	char		**temp;

	init(&q);
	r[0][0] = cat_arg(r[0][0], q, warehouse->envp);
	if (!ft_strcmp(r[0][0], "") && !r[0][1])
		return (ft_free(*r), 0);
	if (!ft_strcmp(r[0][0], ""))
	{
		temp = *r;
		*r = env_dup(&r[0][1], 1);
		ft_free(temp);
		return (2);
	}
	return (1);
}

int	execute(char ***r, t_wh *warehouse)
{
	int	in;
	int	out;
	int	m;

	in = dup(0);
	out = dup(1);
	if (!checkr(r, warehouse))
		return (1);
	if (checkr(r, warehouse) == 2)
		return (execute(r, warehouse));
	if (is_pipe(*r) != -1)
		return (pipe_cmd(r, warehouse), 1);
	if (redirections(r, warehouse) || !(*r)[0])
		return (dup2(in, 0), dup2(out, 1), ft_free(*r), 1);
	if (redirections_out(r, warehouse) || !(*r)[0])
		return (dup2(in, 0), dup2(out, 1), ft_free(*r), 1);
	m = mini_exec(*r, warehouse);
	clean(*r, warehouse);
	if (m == -1)
		default_exec(*r, warehouse);
	return (dup2(in, 0), dup2(out, 1), ft_free(*r), 1);
}
