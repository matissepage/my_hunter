##
## EPITECH PROJECT, 2019
## PSU_my_printf_bootstrap_2019
## File description:
## Makefile
##

SRC		=	./src/main.c 			\
			./src/ballon.c 			\
			./src/event.c 			\
			./src/sound.c 			\
			./src/cursor.c 			\
			./src/window.c 			\

OBJ		= $(SRC:.c=.o)

CC 		= gcc

LIB		= make -C ./lib/my

RM		= rm -f

NAME	= my_hunter

CFLAGS	= -Wall -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: 		$(NAME)

$(NAME):	
		$(LIB)
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) ./lib/libmy.a

tests_run:
		$(LIB)
		gcc -o units tests/*.c --coverage -lcriterion ./lib/libmy.a
		./units

clean:
		$(LIB) clean
		$(RM) $(OBJ)
		$(RM) *.gcda
		$(RM) *.gcno

fclean: clean
		$(RM) $(NAME)
		$(RM) units
		$(LIB) fclean

re:		fclean all