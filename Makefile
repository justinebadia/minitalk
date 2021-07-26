NAME_C = client
NAME_S = serveur

SRCS_DIR = srcs
OBJ_DIR = obj

HDRS = include

C_FILES_C = client.c utils.c
O_FILES_C = $(C_FILES_C:.c=.o)
OBJS_C = $(addprefix $(OBJ_DIR)/, $(O_FILES_C))

C_FILES_S = serveur.c utils.c
O_FILES_S = $(C_FILES_S:.c=.o)
OBJS_S = $(addprefix $(OBJ_DIR)/, $(O_FILES_S))

SRCS = $(addprefix $(SRCS_DIR)/, $(C_FILES_C))
SRCS += $(addprefix $(SRCS_DIR)/, $(C_FILES_S))


CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

$(OBJ_DIR)/%.o :	$(SRCS_DIR)/%.c
	${CC} ${CFLAGS} -I ${HDRS} -c $< -o $@

${NAME_C} : ${OBJ_DIR} ${OBJS_C}
	${CC} ${CFLAGS} ${OBJS_C} -o $@

${NAME_S} : ${OBJ_DIR} ${OBJS_S}
	${CC} ${CFLAGS} ${OBJS_S} -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

all : ${NAME_C} ${NAME_S}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME_S} ${NAME_C}

re : fclean all

.PHONY: all clean fclean re