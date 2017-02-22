##
## Makefile for client in /home/coskun_a//Directory
## 
## Made by antoine coskun
## Login   <coskun_a@epitech.net>
## 
## Started on  Fri Nov  9 11:30:12 2012 antoine coskun
## Last update Wed Jun 17 11:55:05 2015 COSKUN Antoine
##

SRC=     main.c			\
	 init_co.c		\
	 std/my_memcpy.c	\
	 std/my_putchar.c	\
	 std/my_putstr.c	\
	 std/my_put_nbr.c	\
	 std/my_getnbr.c 	\
	 std/readline.c		\
	 std/my_strlen.c	\
	 std/my_strcmp.c

NAME=    client

OBJ=	 $(SRC:.c=.o)

CC=	 gcc -Wall -W

RM=	 rm -f

all:	 $(NAME)

re:	 fclean all

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -o $(NAME)

clean:
	 rm -f $(OBJ)

fclean:		clean
	 rm -f $(NAME)
