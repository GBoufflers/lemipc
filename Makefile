##
## Makefile for lempic in /home/dell-a_f//projets/depot/lemipc
## 
## Made by florian dell-aiera
## Login   <dell-a_f@epitech.net>
## 
## Started on  Thu Mar 28 10:08:41 2013 florian dell-aiera
## Last update Thu Mar 28 10:25:39 2013 florian dell-aiera
##


NAME	=	lemipc

NAME_2  =	display

SRC	=	main.c\

SRC_2	=	display.c

OBJ	=	$(SRC:.c=.o)

OBJ_2	=	$(SRC_2:.c=.o)

LDFLAGS	=	-lSDL

all:		$(NAME) $(NAME_2)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)
$(NAME_2):	$(OBJ_2)
		cc -o $(NAME_2) $(OBJ_2) $(LDFLAGS)
clean:
		rm -f $(OBJ)
		rm -f $(OBJ_2)
fclean:		clean
		rm -f $(NAME)
		rm -f $(NAME_2)
re:		fclean all