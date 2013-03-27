NAME	=	lemipc

SRC	=	main.c\

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)
		cc -o display -lSDL test.c
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f display
re:		fclean all