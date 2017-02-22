##
## Makefile for  in /home/gentie_r/SVN-depots/Libmy/gentie_r
## 
## Made by GENTIER Remi
## Login   <Gentie_r@etna-alternance.net>
## 
## Started on  Sat Mar 28 16:13:06 2015 GENTIER Remi
## Last update Mon Apr 20 10:02:13 2015 GENTIER Remi
##

NAME	=	libmy.a

CFLAGS	=	-ansi -pedantic -W -Wall -Werror

SRC	=	my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_isneg.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strstr.c \
		my_strncat.c \
		my_strcat.c \
		my_strlen.c \
		my_swap.c \
		my_getnbr.c \
		my_str_to_wordtab.c \
		my_strdup.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:		
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)