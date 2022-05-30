##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makes file
##

LIB_DIR = lib

TESTS_DIR = tests

TESTS_EXE	= tester.sh

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
	gcc -g3 -o $(NAME) $(SRC) $(wildcard lib/my/src/*.c) $(CFLAGS)

library:
	@cd $(LIB_DIR) && make

tests_run:	all
	@cp $(NAME) $(TESTS_DIR)
	@cd $(TESTS_DIR) && ./$(TESTS_EXE)

clean:
	rm -f $(OBJ)
	@cd $(LIB_DIR) && make clean

fclean:	clean
	rm -f $(NAME)
	rm -f -r $(FOLDER)
	@cd $(LIB_DIR) && make fclean

re:	fclean	all
