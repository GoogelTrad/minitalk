SRC_CLIENT = client.c
SRC_SERVEUR = serveur.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME_SERVEUR = serveur
NAME_CLIENT = client
all: $(NAME_CLIENT) $(NAME_SERVEUR)

$(NAME_CLIENT): $(OBJS)
	ar rcs $(NAME_SERVEUR) $(OBJS)

$(NAME_SERVEUR): $(OBJS)
	ar rcs $(NAME_SERVEUR) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I includes/ -c $< -o $(<:.c=.o)

clean: 
	rm -rf $(OBJS)

fclean: clean 
	rm -rf $(NAME_SERVEUR)
	rm -rf $(NAME_CLIENT)

re: fclean all

