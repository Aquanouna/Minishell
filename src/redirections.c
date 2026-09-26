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

int	in_redir(char *file, t_wh *warehouse, int f)
{
	int	fd;

	if (f > 1)
		close(f);
	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		warehouse->exit_status = 1;
		return (ft_printf(2, "minishell: %s: %s\n", file,
				strerror(errno)), free(file), -1);
	}
	free(file);
	return (fd);
}

int	out_redir_app(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(file);
		return (free(file), 1);
	}
	dup2(fd, 1);
	close(fd);
	return (free(file), 0);
}

int	out_redir(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (free(file), 1);
	}
	dup2(fd, 1);
	close(fd);
	return (free(file), 0);
}
