/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:25:39 by palkhour          #+#    #+#             */
/*   Updated: 2026/02/24 16:25:42 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	baby_realloc(t_wh *warehouse, char *temp, int *wh)
{
	if (temp)
		wh[warehouse->f++] = heredoc(temp, warehouse);
	else
		wh[warehouse->f++] = -1;
}

void	baby_here(char	**c, int i, t_redir	r, t_wh *warehouse)
{
	int		j;

	j = 0;
	while (c[i][j])
	{
		fill(&r.q, c[i][j]);
		if (c[i][j] == '<' && c[i][j + 1] &&
			c[i][j + 1] == '<' && check(r.q))
		{
			if (c[i][j + 2])
				r.temp = ft_strdup(&c[i][j + 2]);
			else if (c[i + 1])
			{
				c[i + 1] = cat_arg_wq(c[i + 1], r.q, warehouse->envp);
				r.temp = ft_strdup(c[i + 1]);
				c[i + 1][0] = '\0';
			}
			j++;
			warehouse->fd = realloc_fd(warehouse, r.temp);
		}
		j++;
	}
}

int	baby_heredoc(t_pipe	p, char *delimiter)
{
	char	*r;

	signal(SIGINT, handler);
	close(p.fd[0]);
	while (!g_sig)
	{
		r = readline("> ");
		if (!r && !g_sig)
			return (ft_printf(2, "minishell: warning: here-document "),
				ft_printf(2, "delimited by end-of-file (wanted `%s'\n)",
					delimiter), exit(0), 0);
		if (g_sig)
		{
			g_sig = 0;
			exit(130);
		}
		if (!ft_strcmp(delimiter, r))
			return (free(r), exit(0), 0);
		else
			ft_printf(p.fd[1], "%s\n", r);
		free(r);
	}
	return (close(p.fd[1]), 0);
}
