NAME	= so_long
SRCS	= $(wildcard *.c)
OBJS	= ${SRCS:.c=.o}
LIB		= -L./libft -lft -lmlx
INCLUDE = -Iincludes -Imlx -Ilibft

FLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
LINKS	= -framework OpenGL -framework Appkit
CC		= gcc
RM		= rm -rf

all		: ${NAME}

${NAME} : ${OBJS}
	@make -C libft
	@${CC} ${FLAGS} ${LIB} ${INCLUDE} $(addprefix obj/, ${OBJS}) ${LINKS} -o $@

%.o : %.c
	@mkdir -p obj
	${CC} ${CCFLAGS} ${INCLUDE} -c $< -o obj/$@


clean :
	rm -rf obj

fclean : clean
	rm -rf ${NAME}
	make fclean -C libft

re : fclean all

# .PHONY: all clean fclean re