NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = bonus_client
NAME_SERVER_BONUS = bonus_server
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS = utils_client_fd.c itoa.c

SRCS_CLIENT_BONUS = bonus/client.c
SRCS_SERVER_BONUS = bonus/server.c
SRCS_BONUS = bonus/utils_client_fd.c bonus/itoa.c

OBJC = ${SRCS:.c=.o}
OBJC_C = ${SRCS_CLIENT:.c=.o}
OBJC_S = ${SRCS_SERVER:.c=.o}

OBJC_BONUS = ${SRCS_BONUS:.c=.o}
OBJC_C_BONUS = ${SRCS_CLIENT_BONUS:.c=.o}
OBJC_S_BONUS = ${SRCS_SERVER_BONUS:.c=.o}

all: client server
	
bonus: bonus_server bonus_client

client: ${OBJC_C} ${OBJC}
	${CC} ${CFLAGS} ${OBJC_C} ${OBJC} -o ${NAME_CLIENT}

server: ${OBJC_S} ${OBJC}
	${CC} ${CFLAGS} ${OBJC_S} ${OBJC} -o ${NAME_SERVER}

bonus_server: ${OBJC_S_BONUS} ${OBJC_BONUS}
	${CC} ${CFLAGS} ${OBJC_S_BONUS} ${OBJC_BONUS} -o ${NAME_SERVER_BONUS}

bonus_client: ${OBJC_C_BONUS} ${OBJC_BONUS}
	${CC} ${CFLAGS} ${OBJC_C_BONUS} ${OBJC_BONUS} -o ${NAME_CLIENT_BONUS}

clean: 
	 ${RM} ${OBJC} ${OBJC_C} ${OBJC_S} ${OBJC_BONUS} ${OBJC_C_BONUS} ${OBJC_S_BONUS}

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER} ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

re: fclean all
