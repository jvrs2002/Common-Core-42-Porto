# Name of the executables
CLIENT = client
SERVER = server

# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Source files
CLIENT_SRC = src/client.c
SERVER_SRC = src/server.c

# Object files
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

# Header files
HEADER = include/minitalk.h

# Default rule
all: $(CLIENT) $(SERVER)
	@echo "All files compiled successfully!"

# Rule to build the client executable
$(CLIENT): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)
	@echo "Client compiled successfully!"

# Rule to build the server executable
$(SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)
	@echo "Server compiled successfully!"

# Rule to compile .c files into .o object files
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executables
clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "Object files cleaned!"

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@echo "Executables cleaned!"

# Rebuild everything from scratch
re: fclean all

# Phony targets (to avoid conflicts with files named 'clean', 'fclean', 're')
.PHONY: all clean fclean re