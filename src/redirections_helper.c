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

int	helper2_in(char **str, int *j, t_redir *r, t_wh *warehouse)
{
	if (str[0][*j + 1] && str[0][*j + 1] == '<')
	{
		(*j)++;
		if (!str[0][*j + 1])
			str[1][0] = '\0';
		return (warehouse->fd[warehouse->f++]);
	}
	if (str[0][*j + 1])
		r->temp = ft_strdup(rm_quotes(&str[0][*j + 1], NULL));
	else if (str[1])
	{
		str[1] = cat_arg(str[1], r->q, r->envp);
		r->temp = ft_strdup(str[1]);
		str[1][0] = '\0';
	}
	return (in_redir(r->temp, warehouse, r->fd));
}

int	helper1_in(char **str, int i, t_redir *r, t_wh *warehouse)
{
	int		j;
	char	*temp;

	j = 0;
	temp = ft_strdup(str[i]);
	str[i] = cat_arg_wq(str[i], r->q, r->envp);
	while (str[i][j])
	{
		fill(&r->q, str[i][j]);
		if (str[i][j] == '<' && check(r->q))
		{
			r->fd = helper2_in(&str[i], &j, r, warehouse);
			if (r->fd == -1)
				return (free(temp), r->fd);
		}
		j++;
	}
	free(str[i]);
	clean_r(temp, '<');
	str[i] = temp;
	return (r->fd);
}

int	check_in(char **str, t_wh *warehouse)
{
	int		i;
	t_redir	r;

	i = 0;
	r.fd = 0;
	init(&r.q);
	r.envp = warehouse->envp;
	while (str[i])
	{
		r.fd = helper1_in(str, i, &r, warehouse);
		if (r.fd == -1)
			return (1);
		i++;
	}
	if (r.fd > 1)
	{
		dup2(r.fd, 0);
		close(r.fd);
	}
	return (0);
}

int	redirections(char ***r, t_wh *warehouse)
{
	char	**clean;
	int		c;

	c = check_in(*r, warehouse);
	if (c == 1)
		return (1);
	clean = clean_redirections(*r);
	ft_free(*r);
	*r = clean;
	return (0);
}
