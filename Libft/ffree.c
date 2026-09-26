/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:47:35 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/12 13:47:59 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ffree(char *s)
{
	if (s)
		free(s);
}

void	wh_free(t_wh warehouse)
{
	ft_free(warehouse.declare_env);
	ft_free(warehouse.envp);
	free(warehouse.pwd);
}
