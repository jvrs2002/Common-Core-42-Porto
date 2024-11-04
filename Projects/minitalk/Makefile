CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CLIENT_SRC = src/client.c
SERVER_SRC = src/server.c
CLIENT_BONUS_SRC = src/client_bonus.c
SERVER_BONUS_SRC = src/server_bonus.c

OBJ_DIR = obj
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_BONUS_OBJ = $(OBJ_DIR)/client_bonus.o
SERVER_BONUS_OBJ = $(OBJ_DIR)/server_bonus.o

PRINTF = libftprintf.a
LIBFT = libft.a
LIBS_DIR = libs
PRINTF_PATH = $(LIBS_DIR)/ft_printf
LIBFT_PATH = $(LIBS_DIR)/Libft

all: $(CLIENT) $(SERVER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(PRINTF_PATH)/$(PRINTF):
	@make -C $(PRINTF_PATH) -s

$(LIBFT_PATH)/$(LIBFT):
	@make -C $(LIBFT_PATH) -s

$(CLIENT): $(CLIENT_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDE) $(CLIENT_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(CLIENT)
	@echo "Client compiled successfully"

$(SERVER): $(SERVER_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDE) $(SERVER_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(SERVER)
	@echo "Server compiled successfully"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDE) $(CLIENT_BONUS_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(CLIENT_BONUS)
	@echo "Client bonus compiled successfully"

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDE) $(SERVER_BONUS_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(SERVER_BONUS)
	@echo "Server bonus compiled successfully"

clean:
	@make clean -C $(PRINTF_PATH) -s
	@make clean -C $(LIBFT_PATH) -s
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned"

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@make fclean -C $(PRINTF_PATH) -s
	@make fclean -C $(LIBFT_PATH) -s
	@echo "Executables and libraries cleaned"

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re bonus
