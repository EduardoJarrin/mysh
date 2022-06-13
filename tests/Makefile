##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makes file
##

BIN	=	mysh

FUNC_DIR	=	functional-tests
UNIT_DIR	=	unit-tests

all:	unit	functional

functional:
	cp ../$(BIN) $(FUNC_DIR)
	cd $(FUNC_DIR) && ./tester.sh

unit:
	@cd $(UNIT_DIR) && make

unit-cov:
	@cd $(UNIT_DIR) && make html-cov

clean:
	@cd $(UNIT_DIR) && make clean

fclean:
	@cd $(FUNC_DIR) && rm -rf $(BIN)
	@cd $(UNIT_DIR) && make fclean

re:	fclean	all
