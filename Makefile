##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## build BSQ project
##

SRC = 	sources/algo.c \
	sources/main.c \
	sources/management_array.c \
	sources/management_line.c \
	sources/util.c \

OBJ = $(SRC:.c=.o)

NAME = bsq

CFLAGS += -I./ -Wall

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
.PHONY: all clean fclean re