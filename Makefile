
# --- SRC / OBJ --- #
SRC_PATH	=	./src/

SRC			=	${addprefix ${SRC_PATH}, main.c}

OBJ			=	${SRC:.c=.o}

# --- COMPILER --- #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OFLAGS		=	-lmlx -framework OpenGL -framework AppKit

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

HEADER		=	./inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} -I${HEADER} -c $< -o $@

# --- EXEC / RULES --- #
NAME	=	cub3D
LIBFT	=	./Lib/Libft/

all:	${NAME}

${NAME}:	${OBJ}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${OFLAGS} ${LIBFT}libft.a ${OBJ} -o ${NAME}
	@printf "\n\tcub3D ready ✨\n"

debug:
	${MAKE} DEBUG=1

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean
	${MAKE} all

.PHONY: all debug clean fclean re
