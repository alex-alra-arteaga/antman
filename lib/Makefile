##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that creates library
##

SRC 	=   $(wildcard *.c) \
            $(wildcard ./lib/my/utils/*.c) \
            $(wildcard ./lib/my/*.c) \
            $(wildcard ./lib/my/graphical/*.c)


NAME	=	libmy.a

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -g3 -I./my/utils

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
