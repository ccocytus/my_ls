##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile lib
##

SRC 	= 	my_printf.c			\
			my_getnbr.c 		\
			my_put_nbr.c 		\
			my_putchar.c 		\
			my_putstr.c 		\
			my_strcat.c 		\
			my_strcpy.c 		\
			my_strlen.c 		\
			my_putstr_error.c 	\
			my_putnbr_octal.c 	\
			my_putnbr_hex.c 	\
			my_putnbr_bighex.c 	\
			my_putnbr_u.c 		\
			my_putnbr_float.c	\
			flags_f.c 		\
			flags_c.c	 	\
			flags_s.c		\
			flags_d.c		\
			flags_i.c		\
			flags_md.c		\
			flags_o.c		\
			flags_x.c		\
			flags_bighex.c		\
			flags_u.c 		\
			flags_p.c 		\
			my_strcmp.c		\
			my_strdup.c		\
			mini_printf.c	\

OBJ 	=	$(SRC:.c=.o)

NAME 	= 	libmy.a

RM 	= 	rm -f

all: 	$(NAME)

$(NAME): 	$(OBJ)
	ar rc	$(NAME) $(OBJ)
	cp ./$(NAME) ../
	mkdir -p ../../include/
	cp ./my.h ../../include/
	make clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
