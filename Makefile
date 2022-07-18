# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 11:06:02 by marvin            #+#    #+#              #
#    Updated: 2022/04/10 11:06:02 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf.a

SRC =	ft_printf.c \
		ft_char.c \
		ft_str.c \
		ft_hex_void_ptr.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
