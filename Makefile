NAME	= so_long.out
SRCS	= main.c
OBJS	= ${SRCS:.c=.0}
LIB		= ./libft

FLAGS	= -Wall -Werror -Wextra
LINKS	= -I libft -lmlx -framework OpenGL -framework Appkit
CC		= gcc
RM		= rm -rf

all		: ${NAME}

$(NAME)	: ${OBJS}
		make -C ${LIB}
		ar rcs ${NAME} ${OBJS} ${LIB}/*.o

%.o : %.c
			@echo "Creating Objects..."
			$(CC) $(FLAGS) ${LINKS} -c $< -o $@

clean	:
			@echo "Cleaning binary files..."
			make clean -C ${LIB}
			${RM} ${OBJS}

fclean	: clean
		@echo "Removing Library..."
		make fclean -C ${LIB}
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re