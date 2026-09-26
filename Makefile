# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndahouk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:46:31 by ndahouk           #+#    #+#              #
#    Updated: 2025/05/19 19:50:38 by ndahouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MY_SOURCES = src/main.c\
			src/execute.c\
			src/echo.c\
			src/cd.c\
			src/pwd.c\
			src/env.c\
			src/export.c\
			src/ctrl.c\
			src/utils.c\
			src/export_utils1.c\
			src/export_utils2.c\
			src/export_utils3.c\
			src/unset.c\
			src/redirections.c\
			src/redirections_helper.c\
			src/redirections_helper1.c\
			src/default_exec.c\
			src/pathfinder.c\
			src/out_redir.c\
			src/pipe.c\
			src/tokens.c\
			src/heredoc.c\
			src/heredoc_babies.c\
			src/main_helper.c\
			src/cd_helper.c\
			
MY_OBJECTS = $(MY_SOURCES:.c=.o)

FT = Libft
HEADERS = headers

CFLAGS = -Wall -Wextra -Werror -g -I$(HEADERS) -I$(FT)
LFLAGS = -L$(HEADERS) -L$(FT) -lreadline -lft 

NAME = minishell

all: libft.a $(NAME)

$(NAME): $(MY_OBJECTS) headers/minishell.h $(FT)/libft.a
	cc $(CFLAGS) $(MY_OBJECTS) $(LFLAGS) -o $(NAME)

libft.a:
	make -C Libft

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

fclean: clean
	make fclean -C Libft
	rm -f $(NAME)

clean:
	make clean -C Libft
	rm -f $(MY_OBJECTS)

re: fclean all
