##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/minishell.c\
			src/my_str_to_word_array.c\
			src/my_path_to_word_array.c\
			src/find_my_path.c\
			src/main.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	mysh

CFLAGS += -W -Wall -Wextra -pedantic -I./include

LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
clean:
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f lib/my/libmy.a
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: 	fclean all