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

void	handle_count_c(char *str, int i, int *count, t_quotes q)
{
	if (ft_isspace(str[i]) && !ft_isspace(str[i - 1]) && check(q))
		(*count)++;
	else if (!ft_isspace(str[i]) && !str[i + 1])
		(*count)++;
	if (!ft_isspace(str[i - 1]) && str[i] == '|' && check(q))
		(*count)++;
	if (str[i + 1] && !ft_isspace(str[i + 1])
		&& str[i] == '|' && check(q))
		(*count)++;
}
