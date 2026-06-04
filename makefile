# Program name
NAME = push_swap
# Compiler
CC    = cc
FLAGS = -g -Wall -Wextra -Werror -I libft/

#Libft
LIBFT = libft/libft.a

# Sources
SRC = main.c

# Objects
OBJ_PATH = obj/
OBJ 	 = $(SRC:.c=.o) 
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))

# Targets
all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft --no-print-directory

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C libft --no-print-directory


fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft --no-print-directory


re: fclean all

.PHONY: all clean fclean re