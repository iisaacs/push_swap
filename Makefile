# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 10:58:17 by iisaacs           #+#    #+#              #
#    Updated: 2019/09/10 16:31:56 by iisaacs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

SRCS = commands.c \
	  list_ops.c \
	  list_ops2.c

all: $(NAME) $(NAME2)

$(NAME):	
	@gcc -o $(NAME) $(SRCS) checker.c libft/libft.a

$(NAME2):
	@gcc -o $(NAME2) $(SRCS) push_swap.c algo_help.c libft/libft.a

fclean:
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME2)

re: fclean all
