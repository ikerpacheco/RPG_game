##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## Creates library an cleans
##

DIR =	src

CFLAGS =	-I./include

SRC	=	$(wildcard $(DIR)/*.c)

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
