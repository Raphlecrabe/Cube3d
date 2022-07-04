SRCS_DIR = srcs/

GARBAGE = garbage/

PARSING = parsing/

GNL = getnextline/

RAYCAST = raycast/

SRCS = main.c

SRCS_GARBAGE = garbagecoll.c \

SRCS_PARSING = 	colourutils.c \
				findcolour.c \
				findpath.c \
				map.c \
				parsefc.c \
				parsing.c \
				textcolours.c \
				texture.c \
				textureutils.c \

SRCS_GNL = 	get_next_line.c \
			get_next_line_utils.c \

SRCS_RAYCAST = vectors.c \

OBJ_DIR = objs/

OBJS = 	${SRCS:%.c=${OBJ_DIR}%.o}

OTHER =	${SRCS/GARBAGE:%.c=${OBJ_DIR}/${GARBAGE}%.o} \
		${SRCS/PARSING:%.c=${OBJ_DIR}/${PARSING}%.o} \
		${SRCS/GNL:%.c=${OBJ_DIR}/${GNL}%.o} \
		${SRCS/RAYCAST:%.c=${OBJ_DIR}/${RAYCAST}%.o} \

LIBFT_PATH = libft

NAME= cub3d

CC= gcc

FLAGS= -Wall -Wextra -Werror

LEAKS= -g3 -fsanitize=address

INC_DIR = incs

INCLUDES =	${INC_DIR}/garbage.h \
			${INC_DIR}/cube3d.h \
			${INC_DIR}/get_next_line.h \
			${INC_DIR}/parsing.h \
			${INC_DIR}/raycast.h \

${OBJ_DIR}%.o : ${SRCS_DIR}%.c	${INCLUDES}
				mkdir -p ${OBJ_DIR}
				${CC} ${FLAGS} -c $< -o $@

all: makelib ${NAME}

${NAME}:	Makefile ${OBJS}
			${CC} ${FLAGS} ${OBJS} ${LMLX} ${LIBFT_PATH}/libft.a -o ${NAME}

makelib:
			${MAKE} -C ${LIBFT_PATH}/ all

clean:
			${MAKE} -C ${LIBFT_PATH}/ fclean
			rm -f ${OBJS}
			rm -rf objs

fclean:		clean
			rm -f ${NAME}

re:			fclean all

PHONY= all clean fclean re