NAME = fillit

SRC = main.c validate_tets.c create_tets.c real_solver.c solve.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): 
	make -C libft
	gcc -Werror -Wextra -Wall $(SRC) libft/libft.a -o $(NAME) 

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
