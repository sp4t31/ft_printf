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

SRC =	./src/*.c

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling ft_printf archive"
	$(CC) $(CFLAGS) -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	@echo "Removing object files"
	rm -rf $(OBJ)

fclean: clean
	@echo "Removing archive file"
	rm -rf $(NAME)
	

re: fclean all

.PHONY: all clean fclean re
