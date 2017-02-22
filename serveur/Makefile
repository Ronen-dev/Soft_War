##
## Makefile for  in /home/gentie_r/SVN-depots/Libmy/gentie_r
## 
## Made by GENTIER Remi
## Login   <Gentie_r@etna-alternance.net>
## 
## Started on  Sat Mar 28 16:13:06 2015 GENTIER Remi
## Last update Thu Feb 11 23:07:20 2016 GENTIER Remi
##

NAME	=	server

CFLAGS	=	-W -Wall -Werror

SRC	=	libmy/my_putchar.c \
		libmy/my_putstr.c \
		libmy/my_put_nbr.c \
		libmy/my_isneg.c \
		libmy/my_strcpy.c \
		libmy/my_strncpy.c \
		libmy/my_strcmp.c \
		libmy/my_strncmp.c \
		libmy/my_strstr.c \
		libmy/my_strncat.c \
		libmy/my_strcat.c \
		libmy/my_strlen.c \
		libmy/my_swap.c \
		libmy/my_getnbr.c \
		libmy/my_str_to_wordtab.c \
		libmy/my_strdup.c \
		softwar.c \
		softwar1.c \
		main.c \
		client_function1.c \
		client_function2.c \
		function_mouvement.c \
		function_mouvement2.c \
		function_mouvement3.c \
		function_mouvement4.c \
		init_connection.c \
		loop.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME)
clean:		
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all