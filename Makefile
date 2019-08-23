# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 10:58:17 by iisaacs           #+#    #+#              #
#    Updated: 2019/08/23 11:01:34 by iisaacs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS = checker.c \
	  commands.c \
	  list_ops.c 

all: $(NAME)

$(NAME):	
	@gcc -o $(NAME) $(SRCS) libft/libft.a

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
