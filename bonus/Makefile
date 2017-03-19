CC	=	gcc

BUG	=	gcc -g3

NAME	=	tetris

SRC	=	src/*.c

LIB	=

CFLAGS	=	-W -Wall -Wextra -pedantic -I include

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L lib -lmy -lgnl -lncurses

debug :
		$(BUG) -o $(NAME) $(SRC) $(CFLAGS) -L lib -lmy -lgnl -lncurses

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
