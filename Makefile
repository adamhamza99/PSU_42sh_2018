##
## EPITECH PROJECT, 2018
## jj
## File description:
## eke
##

SRC	=	src/main.c			\
		src/spaces.c	\
		src/main2.c	\
		src/main3.c	\
		src/my_putstr.c		\
		src/error.c	\
		src/cd.c	\
		src/my_strcmp.c	\
		src/my_strlen.c		\
		src/my_strncmp.c		\
		src/my_str_to_word_array.c	\
		src/my_concat_params.c	\
		src/struct.c	\
		src/setenv.c	\
		src/my_printf.c	\
		src/modulo_s.c	\
		src/separator.c	\
		src/prompt.c

OBJ  =  $(SRC:.c=.o)

NAME =  42sh

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC)
		@echo -e "\n\n\n          \033[36m***********************************\033[00m"
		@echo -e "          \033[36m* \033[32mPrograms compiled succesfully !\033[00m \033[36m*\033[00m"
		@echo -e "          \033[36m***********************************\033[00m"
		@echo -e "\n\n                \033[01m=====> \033[31m42sh Projet\033[00m\n"
		@echo -e "\n                \033[01m=====> \033[31mMade by: Adam Hamza, Emeric Kpegba & Mohamed Zakaria\033[00m\n\n\n\n"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all
