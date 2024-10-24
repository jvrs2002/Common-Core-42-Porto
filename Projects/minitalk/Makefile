CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibs/ft_printf -Ilibs/Libft
CLIENT_SRC = src/client.c
SERVER_SRC = src/server.c
CLIENT_BONUS_SRC = src/client_bonus.c
SERVER_BONUS_SRC = src/server_bonus.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
FT_PRINTF_SRC = $(wildcard libs/ft_printf/*.c)
LIBFT_SRC = $(wildcard libs/Libft/*.c)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT = libs/Libft/libft.a
FT_PRINTF = libs/ft_printf/ft_printf.a

all: $(CLIENT) $(SERVER)
	@echo "All files compiled successfully!"

$(LIBFT): $(LIBFT_OBJ)
	@ar rcs $@ $^ 
	@echo "Libft library created!"

$(FT_PRINTF): $(FT_PRINTF_OBJ)
	@ar rcs $@ $^ 
	@echo "ft_printf library created!"

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Client compiled successfully!"

$(SERVER): $(SERVER_OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Server compiled successfully!"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Client bonus compiled successfully!"

$(SERVER_BONUS): $(SERVER_BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Server bonus compiled successfully!"

$(FT_PRINTF_OBJ): libs/ft_printf/%.o: libs/ft_printf/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_OBJ): libs/Libft/%.o: libs/Libft/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@echo "Object files cleaned!"

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(LIBFT) $(FT_PRINTF) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "Executables and libraries cleaned!"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus