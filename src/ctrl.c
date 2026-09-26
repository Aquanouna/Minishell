/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:52:58 by ndahouk           #+#    #+#             */
/*   Updated: 2026/01/05 13:53:00 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	g_sig;

void	handler(int sig)
{
	g_sig = sig;
	close(0);
}

void	handle_sigint(int sig)
{
	g_sig = sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signal(int *exit_status)
{
	if (g_sig == 2)
	{
		if (*exit_status < 128 || *exit_status > 255)
			*exit_status = g_sig + 128;
		g_sig = 0;
	}
}
