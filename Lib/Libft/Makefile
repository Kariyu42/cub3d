
# --- SRC / OBJ --- #
SRC_PATH	=	src/

SRC	=	${addprefix ${SRC_PATH}, ft_atoi.c \
										ft_bzero.c \
										ft_calloc.c \
										ft_isdigit.c \
										ft_itoa.c \
										ft_putchar_fd.c \
										ft_putendl_fd.c \
										ft_putnbr_fd.c \
										ft_putstr_fd.c \
										ft_split.c \
										ft_strchr.c \
										ft_strdup.c \
										ft_strjoin.c \
										ft_strlen.c \
										ft_strncmp.c \
										ft_strrchr.c \
										ft_strtrim.c \
										ft_substr.c}

OBJ	=	${SRC:.c=.o}

# --- COMPILER --- #
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

HEADER	=	inc/

${SRC_PATH}%.o: ${SRC_PATH}%.c
	@${CC} ${CFLAGS} -I${HEADER} -c $< -o $@

### Name of lib ###
NAME	=	libft.a

### Rules ###
all:	${NAME}

${NAME}:	${OBJ}
	@ar rcs ${NAME} ${OBJ}
	@printf "\n\n\n\t$(ITALIC)$(BOLD)$(PALEBLUE)[$(LGREEN)LIBFT$(PALEBLUE)] $(BEIGE)Compiled!$(RESET)\n"

clean:
	@${RM} ${OBJ}
	@printf "\n\t$(ITALIC)$(BOLD)$(CREAM)CLEANED [$(BEIGE)LIBFT .o$(CREAM)] files$(RESET)\n"

fclean:	clean
	@${RM} ${NAME}
	@printf "\n\t$(ITALIC)$(BOLD)$(CHAMPAGNE)libft.a CLEANED$(RESET)\n\n"

re:	fclean all

.PHONY:	all clean fclean re
