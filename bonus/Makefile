##
## Makefile for Makefile in /home/walter_h/CPE_2016_matchstick
## 
## Made by Hugo WALTER
## Login   <walter_h@epitech.net>
## 
## Started on  Mon Feb 13 11:26:50 2017 Hugo WALTER
## Last update Sat Feb 18 01:27:36 2017 Hugo WALTER
##

NAME    =       matchstick

SRC     =	get_next_line.c			\
		initialisation.c		\
		update_tab.c			\
		error_file.c			\
		ia_and_player_turn.c		\
		matchstick.c			\
		lib/my/display.c		\
		lib/my/moduloS.c		\
		lib/my/my_getnbr.c		\
		lib/my/my_printf.c		\
		lib/my/my_putchar.c		\
		lib/my/my_putnbr_base.c		\
		lib/my/my_putnbr_binary.c	\
		lib/my/my_put_nbr.c		\
		lib/my/my_putnbr_hexmax.c	\
		lib/my/my_putnbr_hexmin.c	\
		lib/my/my_putnbr_octal.c	\
		lib/my/my_putnbr_octalint.c	\
		lib/my/my_putnbr_p.c		\
		lib/my/my_putnbr_unsigned.c	\
		lib/my/my_putstr.c		\
		lib/my/my_strcat.c		\
		lib/my/my_strlen.c		\
		lib/my/my_strdup.c		\
		lib/my/my_strcpy.c		\
		lib/my/my_strcmp.c

OBJ     =       $(SRC:.c=.o)

CC      =       gcc

CFLAGS  =       -I./include -Wall -pedantic

RM      =       rm -rf

all:    $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
