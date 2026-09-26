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

void	clean_r(char *temp, char c)
{
	int			i;
	t_quotes	q;

	init(&q);
	i = 0;
	while (temp[i])
	{
		fill(&q, temp[i]);
		if (temp[i] == c && check(q))
			temp[i] = '\0';
		i++;
	}
}

char	**clean_redirections(char **argv)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] != '\0')
			j++;
		i++;
	}
	new = malloc(sizeof(char *) * (j + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] != '\0')
			new[j++] = ft_strdup(argv[i]);
		i++;
	}
	new[j] = NULL;
	return (new);
}
