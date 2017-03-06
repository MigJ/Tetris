##
## Makefile for emacs in /home/detroy_j/delivery/CPool_Day10/lib/my
## 
## Made by jean-baptiste detroyes
## Login   <detroy_j@epitech.net>
## 
## Started on  Fri Oct 14 07:47:24 2016 jean-baptiste detroyes
## Last update Mon Mar  6 15:35:01 2017 detroy_j
##

SRCS	=	srcs/main.c	\
		srcs/options/misc.c	\
		srcs/options/init.c	\
		srcs/options/get.c	\
		srcs/options/get_keys.c	\
		srcs/options/get_keys_bis.c	\
		srcs/options/get_variables.c	\
		srcs/options/errors.c	\
		srcs/options/debug.c	\
		srcs/options/help.c	\
		srcs/options/get_keys_nodisplay.c	\
		srcs/options/free.c	\
		srcs/tetriminos/load.c	\
		srcs/tetriminos/misc.c	\
		srcs/tetriminos/open.c	\
		srcs/tetriminos/order.c	\
		srcs/tetriminos/free.c

FLAGS	=	-Llib -lmy -lncurses

CFLAGS	+=	-Wextra -Wall -I include

OBJ	=	$(SRCS:.c=.o)

NAME	=	tetris

all:	$(NAME)

auteur:
	echo $(USER) > auteur

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:	$(OBJ)
	gcc -g $(OBJ) -o $(NAME) $(FLAGS)

.PHONY: all clean fclean re
