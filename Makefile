NAME_CLIENT = client
NAME_SERVER = server
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS = utils_client_fd.c itoa.c

OBJC = ${SRCS:.c=.o}
OBJC_C = ${SRCS_CLIENT:.c=.o}
OBJC_S = ${SRCS_SERVER:.c=.o}

all: client server
	
client: ${OBJC_C} ${OBJC}
	${CC} ${CFLAGS} ${OBJC_C} ${OBJC} -o ${NAME_CLIENT}

server: ${OBJC_S} ${OBJC}
	${CC} ${CFLAGS} ${OBJC_S} ${OBJC} -o ${NAME_SERVER}
	
clean: 
	 ${RM} ${OBJC} ${OBJC_C} ${OBJC_S}

fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all
