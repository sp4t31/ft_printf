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
		ft_hex_void_ptr.c \
		ft_signed_dec.c \
		ft_unsigned_dec.c \
		ft_unsigned_hex_lc.c \
		ft_unsigned_hex_uc.c \
		ft_calculate_bytes.c \
		ft_putnbr.c \
		ft_putnbr_hex.c


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
