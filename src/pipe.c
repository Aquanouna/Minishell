/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:39:02 by ndahouk           #+#    #+#             */
/*   Updated: 2026/02/02 12:39:26 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	is_pipe(char **r)
{
	int	i;

	i = 0;
	while (r[i])
	{
		if (!ft_strcmp(r[i], "|"))
			return (i);
		i++;
	}
	return (-1);
}

void	handle_cmd(t_pipe *p, t_wh *warehouse, int n)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (n == 1)
	{
		free(warehouse->fd);
		warehouse->fd = p->fd1;
		execute(&(p->cmd1), warehouse);
	}
	if (n == 2)
	{
		free(warehouse->fd);
		warehouse->f = 0;
		warehouse->fd = p->fd2;
		warehouse->fd = ft_intdup(warehouse);
		execute(&(p->cmd2), warehouse);
	}
}

void	handle_fd(int fd[], int f)
{
	dup2(fd[f], f);
	close(fd[1]);
	close(fd[0]);
}

void	children(t_pipe *p, t_wh *warehouse)
{
	p->c1 = fork();
	if (p->c1 < 0)
		perror("fork fail");
	if (p->c1 == 0)
	{
		handle_fd(p->fd, 1);
		handle_cmd(p, warehouse, 1);
		exit(warehouse->exit_status);
	}
	p->c2 = fork();
	if (p->c2 < 0)
		perror("fork fail");
	if (p->c2 == 0)
	{
		handle_fd(p->fd, 0);
		handle_cmd(p, warehouse, 2);
		exit(warehouse->exit_status);
	}
	close(p->fd[1]);
	close(p->fd[0]);
}

int	pipe_cmd(char ***r, t_wh *warehouse)
{
	struct s_pipe	p;
	int				*fd;

	if (is_pipe(*r) - 1 < 0 || !(*r)[is_pipe(*r) + 1])
		return (print_unexpected('|', 1, warehouse), ft_free(*r), 1);
	p.cmd1 = env_dup(*r, -count(*r) + is_pipe(*r) + 1);
	p.cmd2 = env_dup(&((*r)[is_pipe(*r) + 1]), 1);
	p.fd1 = ft_intdup(warehouse);
	p.fd1[first_int(warehouse->fd, -1)] = 0;
	fd = ft_intdup(warehouse);
	p.fd2 = &fd[first_int(warehouse->fd, -1) + 1];
	if (pipe(p.fd) == -1)
		return (perror("pipe"), 0);
	signal(SIGINT, SIG_IGN);
	children(&p, warehouse);
	handle_exit(p.c1, warehouse);
	handle_exit(p.c2, warehouse);
	return (free(fd), free(p.fd1), ft_free(p.cmd1),
		ft_free(p.cmd2), ft_free(*r), 1);
}
