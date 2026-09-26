/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:18:02 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/16 15:18:03 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	flag(char *f)
{
	int	i;

	i = 0;
	if (f[i++] == '-' && f[i])
	{
		while (f[i])
		{
			if (f[i] == 'n')
				i++;
			else
				return (-1);
		}
		return (1);
	}
	return (0);
}

char	*handle_dol(char *s, int *i, t_wh *warehouse)
{
	int		j;
	char	*temp;
	char	*e;

	j = 1;
	if (s[*i + 1] && s[*i + 1] == '?')
	{
		printf("%d", warehouse->exit_status);
		(*i)++;
		return ("");
	}
	if (!ft_isalpha(s[*i + j]))
		return ((*i)++, "");
	while (s[*i + j] && !ft_isspace(s[*i + j]) && ft_isalnum(s[*i + j]))
		j++;
	temp = ft_substr(s, *i + 1, j - 1);
	*i += j - 1;
	e = get_env(temp, warehouse->envp);
	free(temp);
	if (e)
		return (e);
	return ("");
}

void	echo_print(char *s, int space, t_wh *warehouse)
{
	int			i;
	t_quotes	q;

	i = 0;
	init(&q);
	while (s[i])
	{
		fill(&q, s[i]);
		if (q.full == 1 && s[i] == '$' && s[i + 1] && !ft_isspace(s[i + 1])
			&& (s[i + 1] == '?' || ft_isalnum(s[i + 1])))
			printf("%s", handle_dol(s, &i, warehouse));
		else if (check(q) && s[i] == '$' && s[i + 1] && !ft_isspace(s[i + 1])
			&& (ft_isalnum(s[i + 1]) || s[i + 1] == '?' || s[i + 1] == '"'))
			printf("%s", handle_dol(s, &i, warehouse));
		else if ((s[i] == '\'' && q.single == 2) || (s[i] == '"' && q.full == 2)
			|| (s[i] != '"' && s[i] != '\''))
			printf("%c", s[i]);
		i++;
	}
	if (space)
		printf(" ");
}

void	echo(char **s, t_wh *warehouse)
{
	int	i;
	int	newline;
	int	word;

	i = 0;
	word = 0;
	newline = 1;
	while (s[i])
	{
		if (flag(s[i]) == 1 && !word)
			newline = 0;
		else
		{
			word = 1;
			if (s[i + 1])
				echo_print(s[i], 1, warehouse);
			else
				echo_print(s[i], 0, warehouse);
		}
		i++;
	}
	if (newline)
		printf("\n");
	warehouse->exit_status = 0;
}
