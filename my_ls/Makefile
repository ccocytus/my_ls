##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_ls
##

SRC	=	my_ls.c		\
		perms.c	\
		check_flag.c	\
		path_file.c	\
		int_str.c	\
		counter.c	\
		disp.c	\
		reopen_dir.c	\
		display.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra

NAME	=	my_ls

all : $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -L ./lib -lmy

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a
re: fclean all
