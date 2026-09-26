/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:30:27 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/21 13:30:29 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	handle_child(char *path, char **r, t_wh *warehouse)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	execve(path, &r[0], warehouse->envp);
	ft_printf(2, "%s: %s\n", path, strerror(errno));
	ft_free(r);
	exit(0);
}

void	handle_exit(pid_t p, t_wh *warehouse)
{
	int		status;

	if (waitpid(p, &status, 0) == -1)
		return ;
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2 || WTERMSIG(status) == 3)
			warehouse->exit_status = 128 + WTERMSIG(status);
	}
	if (WIFEXITED(status))
		warehouse->exit_status = WEXITSTATUS(status);
}

void	err(int e, t_wh *warehouse, char *cmd)
{
	if (e == 0)
	{
		ft_printf(2, "minishell: %s: Is a directory\n", cmd);
		warehouse->exit_status = 126;
		return ;
	}
	if (e == 1)
	{
		ft_printf(2, "%s: command not found\n", cmd);
		warehouse->exit_status = 127;
		return ;
	}
	if (e == 2)
	{
		warehouse->exit_status = 127;
		if (errno == ENOTDIR)
			warehouse->exit_status = 126;
		if (ft_strchr(cmd, '/'))
			ft_printf(2, "minishell: %s: %s\n", cmd, strerror(errno));
		else
			ft_printf(2, "%s: command not found\n", cmd);
	}
}

char	*error(char *cmd, t_wh *warehouse)
{
	struct stat	stats;

	stat(cmd, &stats);
	if (!access(cmd, F_OK))
	{
		if (S_ISDIR(stats.st_mode))
		{
			if (ft_strchr(cmd, '/'))
				return (err(0, warehouse, cmd), NULL);
			else
				return (err(1, warehouse, cmd), NULL);
		}
		if (!ft_strchr(cmd, '/'))
			return (err(1, warehouse, cmd), NULL);
		if (!access(cmd, X_OK))
			return (cmd);
		warehouse->exit_status = 126;
		ft_printf(2, "minishell: %s: %s\n", cmd, strerror(errno));
	}
	else
		err(2, warehouse, cmd);
	return (NULL);
}

int	default_exec(char **r, t_wh *warehouse)
{
	char	*path;
	pid_t	p;

	path = find(rm_quotes(r[0], NULL), warehouse);
	if (!path)
		return (0);
	p = fork();
	signal(SIGINT, SIG_IGN);
	if (p == 0)
		handle_child(path, r, warehouse);
	else if (p < 0)
	{
		if (ft_strcmp(path, r[0]))
			free(path);
		return (perror("fork fail"), 0);
	}
	handle_exit(p, warehouse);
	if (ft_strcmp(path, r[0]))
		free(path);
	return (0);
}
