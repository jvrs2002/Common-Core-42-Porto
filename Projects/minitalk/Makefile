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
	@echo "All files compiled successfully"
	
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

client: $(CLIENT_OBJ)
	@make -C $(PRINTF_PATH) > /dev/null
	@make -C $(LIBFT_PATH) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(CLIENT_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(CLIENT)
	@echo "Client compiled successfully"

server: $(SERVER_OBJ)
	@make -C $(PRINTF_PATH) > /dev/null
	@make -C $(LIBFT_PATH) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(SERVER_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(SERVER)
	@echo "Server compiled successfully"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

client_bonus: $(CLIENT_BONUS_OBJ)
	@make -C $(PRINTF_PATH) > /dev/null
	@make -C $(LIBFT_PATH) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(CLIENT_BONUS_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(CLIENT_BONUS)
	@echo "Client bonus compiled successfully"

server_bonus: $(SERVER_BONUS_OBJ)
	@make -C $(PRINTF_PATH) > /dev/null
	@make -C $(LIBFT_PATH) > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDE) $(SERVER_BONUS_OBJ) $(PRINTF_PATH)/$(PRINTF) $(LIBFT_PATH)/$(LIBFT) -o $(SERVER_BONUS)
	@echo "Server bonus compiled successfully"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned"

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@make -C $(PRINTF_PATH) fclean > /dev/null
	@make -C $(LIBFT_PATH) fclean > /dev/null
	@echo "Executables and libraries cleaned"

re: fclean all

rebonus: fclean bonus

.PHONY: all client server clean fclean re bonus client_bonus server_bonus rebonus