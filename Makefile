#SHELL := bash
# Makefile is written with bash as the shell
# ZSH ?

.SHELLFLAGS := -eu -o pipefail -c
# Bash strict mode prevents subtle bugs
.DELETE_ON_ERROR:
# Makefile deletes any target file whose build 
# sequence completes with non-zero return status
MAKEFLAGS += --warn-undefined-variables
# Receive warning when referring to make variables
# that don't exist

NAME	= ft_printf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC =	./src/ft_printf.c ./src/ft_print_str.c \
		./src/ft_print_nbr.c ./src/ft_calculate_bytes.c \
		./src/ft_putchar.c

OBJ		= $(SRC:.c=.o)
#OBJ_DEST = mv *.o src
OBJ_DEST = objects

all: $(NAME)

$(NAME):
	@echo "Creating $(NAME)"
	$(CC) $(CFLAGS) $(SRC)

	ar -rcs $(NAME) $(OBJ)

clean:
	@echo "Removing object files"
	rm -rf $(OBJ)
#	Removes any files matching $(OBJ), asthe object
#	files are already in the archive

fclean: clean
	@echo "Removing archive file"
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
#	Make will not look for a file named `test` 
#	on the file system, but will view the keywords
#	as functions


# $(NAME):
#	ar - archiver command compiles archive '.a' file
#	-r - flag inserts files into archive & replaces
#		 files of the same name
#	-s - flag represents ranlib command to create/update
#		 an object-file index into the archive

# Questions
#	substitutions (SRC:.c=.o) vs building files (%.o: %.c)