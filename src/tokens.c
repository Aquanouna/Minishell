/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:56:51 by ndahouk           #+#    #+#             */
/*   Updated: 2026/02/03 12:56:53 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	tokens(char c)
{
	if (c == '(' || c == ')' || c == '&'
		|| c == ';' || c == '<' || c == '>')
	{
		return (1);
	}
	return (0);
}

int	print_unexpected(char c, int a, t_wh *warehouse)
{
	if (a < 0)
	{	
		ft_printf(2, "minishell: syntax error ");
		ft_printf(2, "near unexpected token `newline'\n");
	}
	else
		ft_printf(2, "minishell: syntax error near unexpected token `%c'\n", c);
	warehouse->exit_status = 2;
	return (1);
}

int	unexpected_help(char **str, int i, int j, t_wh *warehouse)
{
	if (((!str[i][j + 1] && !str[i + 1])) || str[i][j + 1] == '#')
		return (print_unexpected(str[i][j + 1], -1, warehouse));
	else if (tokens(str[i][j + 1]) && str[i][j + 1] != str[i][j])
		return (print_unexpected(str[i][j + 1], 1, warehouse));
	else if (!str[i][j + 1] && str[i + 1] && str[i + 1][0] == '#')
		return (print_unexpected(str[i][j + 1], -1, warehouse));
	else if (!str[i][j + 1] && str[i + 1] && tokens(str[i + 1][0]))
		return (print_unexpected(str[i + 1][0], 1, warehouse));
	else if (str[i][j + 1] && str[i][j + 1] == str[i][j]
		&& ((!str[i][j + 2] && !str[i + 1]) ||
			(str[i][j + 2] && str[i][j + 2] == '#')))
		return (print_unexpected(str[i][j + 1], -1, warehouse));
	else if (str[i][j + 1] && str[i][j + 1] == str[i][j]
			&& tokens(str[i][j + 2]))
		return (print_unexpected(str[i][j + 2], 1, warehouse));
	else if (str[i][j + 1] && !str[i][j + 2] && str[i + 1] &&
			str[i][j + 1] == str[i][j]
		&& tokens(str[i + 1][0]))
		return (print_unexpected(str[i + 1][0], 1, warehouse));
	return (0);
}

int	unexpected_tok(char **str, t_wh *warehouse)
{
	int			i;
	int			j;
	t_quotes	q;

	i = 0;
	init(&q);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			fill(&q, str[i][j]);
			if ((str[i][j] == '<' && check(q)) ||
				(str[i][j] == '>' && check(q)))
				return (unexpected_help(str, i, j, warehouse));
			j++;
		}
		i++;
	}
	return (0);
}
