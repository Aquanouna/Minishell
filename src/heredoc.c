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

int	heredoc(char *delimiter, t_wh *warehouse)
{
	t_pipe	p;

	rm_quotes(delimiter, NULL);
	if (pipe(p.fd) == -1)
		return (perror("pipe fails!"), 0);
	signal(SIGINT, SIG_IGN);
	p.c1 = fork();
	if (p.c1 < 0)
		return (perror("fork fail"), 0);
	if (p.c1 == 0)
		exit(baby_heredoc(p, delimiter));
	close(p.fd[1]);
	handle_exit(p.c1, warehouse);
	signal(SIGINT, handle_sigint);
	free(delimiter);
	return (p.fd[0]);
}

int	*realloc_fd(t_wh *warehouse, char *temp)
{
	int	*wh;
	int	i;

	wh = ft_calloc(warehouse->f + 2, sizeof(int));
	if (!wh)
		return (NULL);
	if (warehouse->f == 0)
		return (baby_realloc(warehouse, temp, wh), wh);
	i = 0;
	while (warehouse->fd[i])
	{
		wh[i] = warehouse->fd[i];
		i++;
	}
	baby_realloc(warehouse, temp, wh);
	free(warehouse->fd);
	return (wh);
}

int	*ft_intdup(t_wh *warehouse)
{
	int	*fd;
	int	i;

	i = 0;
	while (warehouse->fd[i])
		i++;
	fd = ft_calloc(i + 1, sizeof(int));
	if (!fd)
		return (NULL);
	i = 0;
	while (warehouse->fd[i])
	{
		fd[i] = warehouse->fd[i];
		i++;
	}
	return (fd);
}

int	here(char **rl, t_wh *warehouse)
{
	int		i;
	t_redir	r;
	char	**c;

	c = env_dup(rl, 1);
	if (unexpected_tok(c, warehouse))
		return (ft_free(c), ft_free(rl), 0);
	i = 0;
	warehouse->f = 0;
	init(&r.q);
	while (c[i])
	{
		c[i] = cat_arg_wq(c[i], r.q, warehouse->envp);
		if (!ft_strcmp(c[i], "|"))
			warehouse->fd = realloc_fd(warehouse, NULL);
		baby_here(c, i, r, warehouse);
		i++;
	}
	warehouse->f = 0;
	return (ft_free(c), 1);
}
