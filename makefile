# Program name
NAME = push_swap
BONUS_NAME = checker
# Compiler
CC    = cc
FLAGS = -g -Wall -Wextra -Werror -I libft/

#Libft
LIBFT = libft/libft.a

# Sources
SRC = main.c stack.c debug.c parse_args.c operations.c sort.c
BONUS_SRC = checker_bonus.c stack.c parse_args.c operations.c

# Objects
OBJ_PATH = obj/
OBJ 	 = $(SRC:.c=.o) 
OBJS	 = $(addprefix $(OBJ_PATH), $(OBJ))
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJS = $(addprefix $(OBJ_PATH), $(BONUS_OBJ))

# Targets
all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(OBJ_PATH) $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft --no-print-directory

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C libft --no-print-directory


fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C libft --no-print-directory


re: fclean all

.PHONY: all bonus clean fclean re
