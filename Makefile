##
## Makefile for lempic in /home/dell-a_f//projets/depot/lemipc
## 
## Made by florian dell-aiera
## Login   <dell-a_f@epitech.net>
## 
## Started on  Thu Mar 28 10:08:41 2013 florian dell-aiera
## Last update Thu Mar 28 16:55:01 2013 florian dell-aiera
##


NAME	=	lemipc
NAMED	=	display


SRC	=	main.c\
		get.c\
		players.c\
		isleaving.c\
		get_new_pos.c\
		steps.c\
		lock.c

SRCD	=	display.c

OBJ	=	$(SRC:.c=.o)
OBJD	=	$(SRCD:.c=.o)

LDFLAGS	=	-lSDL

all:		$(NAME) $(NAMED)

$(NAME):	$(OBJ) $(OBJD)
		cc -o $(NAME) $(OBJ)

$(NAMED):	$(OBJD)
		cc -o $(NAMED) $(OBJD) $(LDFLAGS)
clean:
		rm -f $(OBJ) $(OBJD)

fclean:		clean
		rm -f $(NAME) $(NAMED)

re:		fclean all