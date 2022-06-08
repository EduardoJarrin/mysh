##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makes files
##

TEST	=	unit_tests

TEST_SRC	=	$(wildcard src/*.c)

HTML	=	coverage

LIB_DIR	= $(realpath ../lib)

BIN_SRC	=	$(wildcard ../src/*.c)
BIN_SRC	:=	$(filter-out ../src/main.c, $(BIN_SRC))

CCTMP	=	$(BIN_SRC:.c=.gcno) $(BIN_SRC:.c=.gcda) $(BIN_SRC:.c=.gcov) \
			$(TEST_SRC:.c=.gcno) $(TEST_SRC:.c=.gcda) $(TEST_SRC:.c=.gcov)

CFLAGS = -W -Wall -Wextra -Wno-unknown-pragmas
CFLAGS += -iquote -I./include -I../include -I$(LIB_DIR)/my/include

LDFLAGS = -lcriterion -lgcov --coverage -g -O0 -lcrypto -L$(LIB_DIR) -lmy

all:	run

library:
	@cd $(LIB_DIR) && make

tests:	library
	gcc -o $(TEST) $(TEST_SRC) $(BIN_SRC) $(LDFLAGS) $(CFLAGS)

run:	tests
	./$(TEST)

html-details: run
	gcovr -r .. --html-details -o $(HTML).html

clean:
	rm -f $(OBJ)

cclean:
	rm -f $(CCTMP)
	rm -f $(TEST)-*
	rm -f $(HTML).*

fclean:	clean	cclean
	@cd $(LIB_DIR) && make fclean
	rm -f $(TEST)


re:	fclean	all
