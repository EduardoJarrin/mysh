##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makes file
##

LIB_DIR = lib

LDFLAGS	=	-L$(LIB_DIR) -lmy

CFLAGS	=	-W -Werror -Wall -Wextra

CFLAGS	+=	-I./include -I$(LIB_DIR)/my/include

SRC_DIR	=	src

SRC	=	$(wildcard $(SRC_DIR)/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	binary

binary:	library	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

debugging:
	gcc -g3 -o $(NAME) $(SRC) $(wildcard lib/*/src/*.c) $(CFLAGS)

library:
	@cd $(LIB_DIR) && make

clean:
	rm -f $(OBJ)
	@cd $(LIB_DIR) && make clean

fclean:	clean
	rm -f $(NAME)
	rm -f -r $(FOLDER)
	@cd $(LIB_DIR) && make fclean

re:	fclean	all
