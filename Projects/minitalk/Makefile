CFLAGS = -Wall -Wextra -Werror

CFILES = client.c server.c

OFILES = $(CFILES:.c=.o)

NAME = .a

CC = gcc

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re