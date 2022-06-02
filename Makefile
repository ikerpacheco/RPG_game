##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makes file
##

LIB_DIR = lib

LDFLAGS	=	-L$(LIB_DIR) -lmy

LDFLAGS	+=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

CFLAGS	=	-W -Werror -Wall -Wextra -Wundef

CFLAGS	+=	-I./include -I$(LIB_DIR)/my/include

DIR	=	src

SRC	=	$(wildcard $(DIR)/*.c)

SRC	+=	$(wildcard $(DIR)/*/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	binary

binary:	library	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

debugging: library
	gcc -g3 -o $(NAME) $(SRC) $(LDFLAGS) $(CFLAGS)

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
