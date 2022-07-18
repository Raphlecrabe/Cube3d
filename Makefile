SRCS_DIR = srcs/

GARBAGE = garbage/

PARSING = parsing/

GNL = getnextline/

RAYCAST = raycast/

DISPLAY = display/

DEBUG = debug/

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
				raycast.c \
				stripe.c \

SRCS_DISPLAY = display.c \

SRCS_DEBUG = debug_raycast.c \

OBJ_DIR = objs/

OBJS = 	${SRCS:%.c=${OBJ_DIR}%.o}

OTHER =	${SRCS/GARBAGE:%.c=${OBJ_DIR}/${GARBAGE}%.o} \
		${SRCS/PARSING:%.c=${OBJ_DIR}/${PARSING}%.o} \
		${SRCS/GNL:%.c=${OBJ_DIR}/${GNL}%.o} \
		${SRCS/RAYCAST:%.c=${OBJ_DIR}/${RAYCAST}%.o} \

SRCS_DEBUG_ABS = ${SRCS_DEBUG:%.c=${DEBUG}%.c}

SRCS_GARBAGE_ABS = ${SRCS_GARBAGE:%.c=${GARBAGE}%.c}

SRCS_GNL_ABS = ${SRCS_GNL:%.c=${GNL}%.c}

SRCS_RAYCAST_ABS = ${SRCS_RAYCAST:%.c=${RAYCAST}%.c}

SRCS_DISPLAY_ABS = ${SRCS_DISPLAY:%.c=${DISPLAY}%.c}

OBJS_DEBUG = ${SRCS_DEBUG_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_GARBAGE_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_GNL_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_RAYCAST_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_DISPLAY_ABS:%.c=${OBJ_DIR}%.o} \

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
				mkdir -p ${OBJ_DIR}${GNL}
				mkdir -p ${OBJ_DIR}${GARBAGE}
				mkdir -p ${OBJ_DIR}${RAYCAST}
				mkdir -p ${OBJ_DIR}${DEBUG}
				mkdir -p ${OBJ_DIR}${DISPLAY}
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

debug:		makelib Makefile ${OBJS_DEBUG}
			${CC} ${OBJS_DEBUG} ${LMLX} ${LIBFT_PATH}/libft.a -o ${NAME}

PHONY= all clean fclean re