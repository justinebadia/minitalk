NAME_C = client
NAME_S = serveur

NAME_C_BONUS = client_bonus
NAME_S_BONUS = serveur_bonus

SRCS_DIR = srcs
OBJ_DIR = obj
BONUS_SRCS_DIR = srcs_bonus
BONUS_OBJ_DIR = obj_bonus

HDRS = include
HDRS_BONUS = include_bonus

C_FILES_C = client.c utils.c
O_FILES_C = $(C_FILES_C:.c=.o)
OBJS_C = $(addprefix $(OBJ_DIR)/, $(O_FILES_C))

BONUS_CFILES_C = client_bonus.c utils_bonus.c
BONUS_OFILES_C = $(BONUS_CFILES_C:.c=.o)
OBJS_C_BONUS = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_OFILES_C))

C_FILES_S = serveur.c utils.c
O_FILES_S = $(C_FILES_S:.c=.o)
OBJS_S = $(addprefix $(OBJ_DIR)/, $(O_FILES_S))

BONUS_CFILES_S = serveur_bonus.c utils_bonus.c
BONUS_OFILES_S = $(BONUS_CFILES_S:.c=.o)
OBJS_S_BONUS = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_OFILES_S))

SRCS = $(addprefix $(SRCS_DIR)/, $(C_FILES_C))
SRCS += $(addprefix $(SRCS_DIR)/, $(C_FILES_S))

SRCS_BONUS = $(addprefix $(BONUS_SRCS_DIR)/, $(BONUS_CFILES_C))
SRCS_BONUS += $(addprefix $(BONUS_SRCS_DIR)/, $(BONUS_CFILES_S))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

$(OBJ_DIR)/%.o :	$(SRCS_DIR)/%.c
	${CC} ${CFLAGS} -I ${HDRS} -c $< -o $@

$(BONUS_OBJ_DIR)/%.o :	$(BONUS_SRCS_DIR)/%.c
	${CC} ${CFLAGS} -I ${HDRS_BONUS} -c $< -o $@

${NAME_C} : ${OBJ_DIR} ${OBJS_C}
	${CC} ${CFLAGS} ${OBJS_C} -o $@

${NAME_C_BONUS} : ${BONUS_OBJ_DIR} ${OBJS_C_BONUS}
	${CC} ${CFLAGS} ${OBJS_C_BONUS} -o $@

${NAME_S} : ${OBJ_DIR} ${OBJS_S}
	${CC} ${CFLAGS} ${OBJS_S} -o $@

${NAME_S_BONUS} : ${BONUS_OBJ_DIR} ${OBJS_S_BONUS}
	${CC} ${CFLAGS} ${OBJS_S_BONUS} -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR) : 
	mkdir -p $(BONUS_OBJ_DIR)

all : ${NAME_C} ${NAME_S}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME_S} ${NAME_C}

bonus : ${NAME_C_BONUS} ${NAME_S_BONUS}

re : fclean all

.PHONY: all clean fclean re bonus