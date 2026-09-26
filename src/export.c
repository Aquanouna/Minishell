/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:13:30 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/10 14:06:58 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	export(char **s, t_wh *warehouse)
{
	int			i;
	t_quotes	q;

	warehouse->exit_status = 0;
	if (!s[0])
	{
		print(warehouse->declare_env);
		return ;
	}
	i = 0;
	while (s[i])
	{
		init(&q);
		s[i] = cat_arg(s[i], q, warehouse->envp);
		if (!s[i])
			return ;
		e_help(s[i], warehouse);
		i++;
	}
}
