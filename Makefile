NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT_FILE = client
SERVEUR_FILE = server

OBJS_DIR = ./objets/
LIBFT_PATH = ./libft

SRC = $(addsuffix .c, $(CLIENT_FILE) $(SERVEUR_FILE))
OBJ = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
NC = \033[0m

LIBFT = $(LIBFT_PATH)/libft.a

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJS_DIR)client.o $(LIBFT) -o client
	@$(CC) $(CFLAGS) $(OBJS_DIR)server.o $(LIBFT) -o server
	@echo "$@ : $(BLUE)[READY]$(NC)"

$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@clear
	@echo "libft : $(GREEN)[OK]$(NC)"

all: $(NAME)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@$(RM) client server
	@make fclean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all

.PHONY: all clean fclean re
