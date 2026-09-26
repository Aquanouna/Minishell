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

int	helper2_out(char **str, int i, int *j, t_redir *r)
{
	if (str[i][*j + 1] && str[i][*j + 1] == '>')
	{
		if (str[i][*j + 2])
			r->temp = ft_strdup(&str[i][*j + 2]);
		else if (str[i + 1])
		{
			str[i + 1] = cat_arg(str[i + 1], r->q, r->envp);
			r->temp = ft_strdup(str[i + 1]);
			str[i + 1][0] = '\0';
		}
		(*j)++;
		return (out_redir_app(r->temp));
	}
	if (str[i][*j + 1])
		r->temp = ft_strdup(&str[i][*j + 1]);
	else if (str[i + 1])
	{
		str[i + 1] = cat_arg(str[i + 1], r->q, r->envp);
		r->temp = ft_strdup(str[i + 1]);
		str[i + 1][0] = '\0';
	}
	return (out_redir(r->temp));
}

int	helper1_out(char **str, int i, t_redir *r)
{
	int		j;
	char	*temp;

	j = 0;
	temp = ft_strdup(str[i]);
	str[i] = cat_arg_wq(str[i], r->q, r->envp);
	while (str[i][j])
	{
		fill(&r->q, str[i][j]);
		if (str[i][j] == '>' && check(r->q))
		{
			if (helper2_out(str, i, &j, r))
				return (free(temp), 1);
		}
		j++;
	}
	free(str[i]);
	clean_r(temp, '>');
	str[i] = temp;
	return (0);
}

int	check_out(char **str, t_wh *warehouse)
{
	int		i;
	t_redir	r;

	i = 0;
	init(&r.q);
	r.exit_status = &(warehouse->exit_status);
	r.envp = warehouse->envp;
	while (str[i])
	{
		if (helper1_out(str, i, &r))
			return (1);
		i++;
	}
	return (0);
}

int	redirections_out(char ***r, t_wh *warehouse)
{
	char	**clean;
	int		c;

	c = check_out(*r, warehouse);
	if (c == 1)
		return (warehouse->exit_status = 1, 1);
	clean = clean_redirections(*r);
	ft_free(*r);
	*r = clean;
	return (0);
}
