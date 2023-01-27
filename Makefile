##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles
##

all:
	make -C antman
	make -C giantman

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
