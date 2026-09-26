/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:31:38 by ndahouk           #+#    #+#             */
/*   Updated: 2025/06/10 21:17:31 by ndahouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <errno.h>
# include <linux/limits.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_quotes
{
	int	single;
	int	full;
}	t_quotes;

typedef struct s_wh
{
	char	**envp;
	char	**declare_env;
	int		exit_status;
	int		*fd;
	int		f;
	char	*pwd;
}	t_wh;

void	ft_free(char **s);
void	wh_free(t_wh warehouse);
void	fill(t_quotes *q, char c);
int		check(t_quotes q);
void	init(t_quotes *q);
int		ft_isspace(char c);
char	*find(char	*cmd, t_wh *warehouse);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*error(char *cmd, t_wh *warehouse);
char	*ft_join(char *s1, char *s2);
void	ffree(char *s);
int		ft_first(char *s, char c);
int		ft_last(char *s, char c);
char	**env_dup(char *envp[], int n);
int		count(char *envp[]);
int		first_int(int *s, int c);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_strcmp(const char *s1, const char *s2);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char *str, t_wh *warehouse);
char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f) (unsigned int, char *));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char	*s, int fd);

void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list	*lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list	**lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(int fd, const char *s, ...);
int		ft_putchar(int fd, char c);
int		ft_putnbr(int fd, int n);
int		ft_putptr(int fd, void *ptr);
int		ft_putstr(int fd, char *s);
int		ft_putuns(int fd, unsigned int n);
int		ft_puthex(int fd, unsigned int n, int c);
void	handle_count_c(char *str, int i, int *count, t_quotes q);
#endif
