/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <ndahouk@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:18:54 by ndahouk           #+#    #+#             */
/*   Updated: 2025/02/19 17:24:27 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(char *str)
{
	int			i;
	int			count;
	t_quotes	q;

	i = 0;
	count = 0;
	init(&q);
	if (ft_strlen(str) == 1)
		count = 1;
	while (str[i])
	{
		fill(&q, str[i]);
		if (i > 0)
			handle_count_c(str, i, &count, q);
		i++;
	}
	if (!check(q))
		return (printf("Error: Unclosed quotes!\n"), -1);
	return (count);
}

int	ft_len(char *str)
{
	int			i;
	t_quotes	q;

	if (!str)
		return (0);
	i = 0;
	init(&q);
	if (str[i] == '|' && check(q))
		return (1);
	while (str[i] && ((!ft_isspace(str[i]) && str[i] != '|') || !(check(q))))
	{
		fill(&q, str[i]);
		i++;
	}
	return (i);
}

int	ft_dup(int *t, char *str, t_quotes *q, char **temp)
{
	int	j;
	int	i;

	i = 0;
	if (str[i] == '|' && check(*q))
	{
		temp[*t] = malloc(2);
		if (!temp[*t])
			return (0);
		temp[*t][0] = '|';
		temp[*t][1] = '\0';
		(*t)++;
		return (1);
	}
	temp[*t] = malloc((ft_len(str) + 1) * sizeof(char));
	if (!temp[*t])
		return (0);
	j = 0;
	while (str[i] && ((!ft_isspace(str[i]) && str[i] != '|') || !check(*q)))
	{
		temp[*t][j++] = str[i];
		fill(q, str[++i]);
	}
	temp[(*t)++][j] = '\0';
	return (i);
}

int	ft_fill(char **temp, int *t, char *str)
{
	int			i;
	int			j;
	t_quotes	q;

	i = 0;
	j = 0;
	init(&q);
	while (str[i])
	{
		fill(&q, str[i]);
		while (str[i] && ft_isspace(str[i]) && check(q))
			fill(&q, str[++i]);
		if (str[i])
		{
			j = ft_dup(t, &str[i], &q, temp);
			if (!j)
				return (0);
			i += j;
		}
		temp[*t] = NULL;
	}
	return (1);
}

char	**ft_split(char *str, t_wh *warehouse)
{
	char	**temp;
	int		t;
	int		size;

	t = 0;
	size = ft_count(str);
	if (size == 0)
	{
		temp = ft_calloc(2, sizeof(char *));
		temp[0] = ft_strdup("");
		return (temp);
	}
	if (size == -1)
	{
		warehouse->exit_status = 2;
		return (NULL);
	}
	temp = malloc((size + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	if (!ft_fill(temp, &t, str))
		return (ft_free(temp), NULL);
	temp[t] = 0;
	return (temp);
}
