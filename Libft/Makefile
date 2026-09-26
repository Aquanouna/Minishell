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
MY_SOURCES = ft_isalpha.c\
			ft_free.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			find.c\
			ft_strndup.c\
			ft_strcat.c\
			ft_join.c\
			ffree.c\
			ft_find.c\
			env_dup.c\
			ft_printf.c\
			ft_puthex.c\
			ft_putnbr.c\
			ft_putptr.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putuns.c\
			ft_count.c\

MY_BONUS_SOURCES = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_BONUS_OBJECTS = $(MY_BONUS_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

bonus: $(MY_BONUS_OBJECTS)
	ar rcs $(NAME) $(MY_BONUS_OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(MY_OBJECTS)
	rm -f $(MY_BONUS_OBJECTS)

re: fclean all
