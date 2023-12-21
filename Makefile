NAME = serverclient.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = printf/libftprintf.a

CLIENT = client
SERVER = server

all: $(SERVER) $(CLIENT)

$(SERVER): $(PRINTF)
	make -C ./printf
	$(CC) $(CFLAGS) -g0 server.c $(PRINTF) -o $@

$(CLIENT): $(PRINTF)
	$(CC) $(CFLAGS) -g0 client.c $(PRINTF) -o $@

$(PRINTF):
	make -C ./printf

clean:
	make fclean -C ./printf
	rm -rf server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re
