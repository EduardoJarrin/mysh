##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## Creates library an cleans
##

SRC_DIR =	src

CFLAGS =	-I./include

SRC	=	$(wildcard $(SRC_DIR)/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all
