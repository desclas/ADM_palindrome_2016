##
## Makefile for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_palindrome_2016
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Thu Jun 15 11:12:35 2017 Mathias
## Last update Thu Jun 15 16:17:42 2017 Mathias
##

SRC	=	test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	palindrome

CFLGS	=	-Iinclude -W -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
