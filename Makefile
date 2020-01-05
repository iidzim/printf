# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 17:32:24 by iidzim            #+#    #+#              #
#    Updated: 2019/12/22 18:10:26 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_convert_address.c ft_convert_cper.c ft_convert_d.c ft_convert_d2.c\
		ft_convert_strings.c ft_convert_u.c ft_convert_x.c ft_more_flags.c\
		ft_printf.c ft_printf_utils.c ft_printf_utils2.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC)
		ar -rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
		rm -rf $(OBJ)
fclean: 
		rm -rf $(NAME)
re: fclean all