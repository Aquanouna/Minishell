/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:45:03 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/13 16:45:05 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**declare(char **envp, int n)
{
	int		i;
	char	**dec;

	i = 0;
	dec = ft_calloc(count(envp) + n, sizeof(char *));
	if (!dec)
		return (NULL);
	while (envp[i])
	{
		dec[i] = ft_join("declare -x ", envp[i]);
		if (!dec[i])
			return (ft_free(dec), NULL);
		i++;
	}
	return (dec);
}

char	**parse_exec(char *c, t_wh *warehouse)
{
	char	**r;

	r = ft_split(c, warehouse);
	free(c);
	if (!r)
		return (NULL);
	return (r);
}

int	try(char *r, t_wh *warehouse)
{
	char	**c;
	int		i;

	warehouse->fd = NULL;
	c = parse_exec(r, warehouse);
	if (!c && warehouse->exit_status != 2)
		return (wh_free(*warehouse), rl_clear_history(), 0);
	if (!c)
		return (1);
	if (!ft_strcmp(c[0], ""))
		return (ft_free(c), 1);
	if (!here(c, warehouse))
		return (1);
	if (c && !execute(&c, warehouse))
		return (wh_free(*warehouse), rl_clear_history(), 0);
	i = 0;
	if (!warehouse->fd)
		return (1);
	while (warehouse->fd[i])
	{
		if (warehouse->fd[i] != -1)
			close(warehouse->fd[i]);
		i++;
	}
	return (free(warehouse->fd), 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*r;
	t_wh	warehouse;

	(void) argc, (void) argv;
	warehouse.exit_status = 0;
	warehouse.envp = envp;
	warehouse.pwd = ft_strdup(getenv("PWD"));
	if (!shell(&warehouse))
		return (ft_printf(2, "error!\n"), 1);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		r = prompt(warehouse.envp);
		if (!r)
			return (printf("exit\n"), rl_clear_history(), wh_free(warehouse), 0);
		handle_signal(&warehouse.exit_status);
		add_history(r);
		if (!try(r, &warehouse))
			return (0);
	}
	return (0);
}
