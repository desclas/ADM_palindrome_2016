##
## Makefile for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Thu Jun 15 11:12:35 2017 Mathias
## Last update Fri Jun 16 11:14:48 2017 Mathias
##

DEBUG	=	yesS

SRC	=	src/main.c		\
		src/find_palin.c	\
		src/opt.c		\
		src/utilities.c		\
		src/all_palin.c

OBJ	=	$(SRC:.c=.o)

NAME	=	palindrome

ifeq ($(DEBUG), yes)
	CFLAGS	=	-Iinclude -W -Wall -Werror -Wextra -g3
else
	CFLAGS	=	-Iinclude -W -Wall -Werror -Wextra
endif

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
