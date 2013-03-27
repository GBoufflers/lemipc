NAME	=	lemipc
NAMED	=	display


SRC	=	main.c\
		players.c\
		isleaving.c\
		get_new_pos.c\
		steps.c\
		lock.c

SRCD	=	display.c

OBJ	=	$(SRC:.c=.o)
OBJD	=	$(SRCD:.c=.o)

all:		$(NAME) $(NAMED)

$(NAME):	$(OBJ) $(OBJD)
		cc -o $(NAME) $(OBJ)
		cc -o $(NAMED) -lSDL $(OBJD)

clean:
		rm -f $(OBJ) $(OBJD)

fclean:		clean
		rm -f $(NAME) $(NAMED)

re:		fclean all