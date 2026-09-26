/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:43:25 by ndahouk           #+#    #+#             */
/*   Updated: 2025/11/13 16:43:29 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_redirections
{
	t_quotes	q;
	int			*exit_status;
	char		*temp;
	char		**envp;
	int			fd;
}	t_redir;

typedef struct s_pipe
{
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	pid_t	c1;
	pid_t	c2;
	int		*fd1;
	int		*fd2;
}	t_pipe;

extern int	g_sig;
void	echo(char **s, t_wh *warehouse);
int		execute(char ***c, t_wh *warehouse);
void	cd(char **s, t_wh *warehouse);
void	pwd(t_wh *warehouse);
void	env(t_wh *warehouse);
char	*rm_quotes(char *s, char *temp);
char	**declare(char **envp, int n);
void	export(char **s, t_wh *warehouse);
void	handle_sigint(int sig);
void	handle_signal(int *exit_status);
char	*get_env(char *s, char *envp[]);
int		checkv(char *s);
void	print(char *s[]);
int		finde(char *v, char *envp[], int n);
int		shell(t_wh *warehouse);
char	*cat_arg(char *s, t_quotes q, char **envp);
int		checkv(char *s);
void	unset(char **s, t_wh *warehouse);
char	*parse(char *s);
void	e_help(char *s, t_wh *warehouse);
void	eexport(char *v, char *s, t_wh *warehouse);
void	dexport(char *v, char *s, t_wh *warehouse, int c);
int		redirections(char ***r, t_wh *warehouse);
char	**clean_redirections(char **argv);
int		in_redir(char *file, t_wh *warehouse, int f);
int		unexpected_tok(char **str, t_wh *warehouse);
int		default_exec(char **r, t_wh *warehouse);
char	*fullpath(char *p, char *here);
int		out_redir(char *file);
int		print_unexpected(char c, int a, t_wh *warehouse);
int		tokens(char c);
int		redirections_out(char ***r, t_wh *warehouse);
int		unexpected_help(char **str, int i, int j, t_wh *warehouse);
void	handle_exit(pid_t p, t_wh *warehouse);
int		pipe_cmd(char ***r, t_wh *warehouse);
int		is_pipe(char **r);
int		out_redir_app(char *file);
int		heredoc(char *delimiter, t_wh *warehouse);
void	handle_fd(int fd[], int f);
void	handler(int sig);
int		here(char **c, t_wh *warehouse);
void	print_int(int	*fd);
int		*ft_intdup(t_wh *warehouse);
void	clean_r(char *temp, char c);
char	*cat_arg_wq(char *s, t_quotes q, char **envp);
char	*prompt(char *envp[]);
char	*tilde(char *s, char *envp[]);
void	clean_r(char *temp, char c);
char	**clean_redirections(char **argv);
char	*handle_dol_ex(char *s, int *i, int exit_status, char *envp[]);
void	baby_realloc(t_wh *warehouse, char *temp, int *wh);
int		baby_heredoc(t_pipe	p, char *delimiter);
void	baby_here(char	**c, int i, t_redir	r, t_wh *warehouse);
int		*realloc_fd(t_wh *warehouse, char *temp);
#endif
