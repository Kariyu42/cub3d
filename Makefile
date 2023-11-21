
# --- SRC / OBJ --- #
SRC_PATH	=	./src/

SRC			=	${addprefix ${SRC_PATH}, main.c \
											parsing/check_color.c \
											parsing/get_texture.c \
											parsing/inspect_dup.c \
											parsing/map_data.c \
											parsing/map_parser.c \
											parsing/map_tools.c \
											parsing/parsing.c}

OBJ			=	${SRC:.c=.o}

# --- COMPILER --- #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OFLAGS		=	-framework OpenGL -framework AppKit

# --- DEBUG PURPOSES --- #
ifdef	DEBUG
	CC	+=	-g
endif

HEADER		=	./inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	@${CC} ${CFLAGS} -I${HEADER} -c $< -o $@

# --- EXEC / RULES --- #
NAME	=	cub3D
LIBFT	=	./Lib/Libft/
MLX		=	./Lib/minilibx/

all:	${NAME}

${NAME}:	${OBJ}
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} ${OFLAGS} ${LIBFT}libft.a ${MLX}libmlx.a ${OBJ} -o ${NAME}
	@printf "\n\tcub3D ready ✨\n"

debug:
	@${MAKE} DEBUG=1

clean:
	@make clean -C ${LIBFT}
	@rm -f ${OBJ}

fclean:	clean
	@rm -f ${LIBFT}libft.a ${NAME}

re:	fclean
	@${MAKE} all

.PHONY: all debug clean fclean re
