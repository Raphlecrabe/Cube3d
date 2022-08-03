SRCS_DIR = srcs/

GARBAGE = garbage/

PARSING = parsing/

GNL = getnextline/

RAYCAST = raycast/

DISPLAY = display/

DEBUG = debug/

SRCS = main.c

SRCS_GARBAGE = 	garbagecoll.c \
				garbageutils.c \
				garbagesplittemp.c \

SRCS_PARSING = 	colourutils.c \
				findcolour.c \
				findpath.c \
				map.c \
				parsefc.c \
				parsing.c \
				testcolours.c \
				texture.c \
				textureutils.c \
				checkholes.c \
				error.c \
				parsemap.c \
				parseopen.c \
				parseopen2.c \
				parseopenutils.c \
				openmap.c \
				initcube.c \
				debugparsing.c \

SRCS_GNL = 	get_next_line.c \
			get_next_line_utils.c \

SRCS_RAYCAST = 	vectors.c \
				raycast.c \
				stripe.c \

SRCS_DISPLAY = 	display.c \
				display_utils.c \
				move.c \
				mlx_utils.c \
				minimap.c \

SRCS_DEBUG = debug_raycast.c \

#OBJS

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

SRCS_PARSING_ABS = ${SRCS_PARSING:%.c=${PARSING}%.c}


OBJS_DEBUG = ${SRCS_DEBUG_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_GARBAGE_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_GNL_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_RAYCAST_ABS:%.c=${OBJ_DIR}%.o} \
			${SRCS_DISPLAY_ABS:%.c=${OBJ_DIR}%.o} \

OBJS_DEBPARSE = ${SRCS_GARBAGE_ABS:%.c=${OBJ_DIR}%.o} \
				${SRCS_PARSING_ABS:%.c=${OBJ_DIR}%.o} \
				${SRCS_GNL_ABS:%.c=${OBJ_DIR}%.o} \

#MLX

IMLX_MACOS = -Imlx

LMLX_MACOS = -Lmlx -lmlx -framework OpenGL -framework AppKit

IMLX_LINUX = -I/usr/include -Imlx_linux -O3

LMLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

#INCLUDES

INC_DIR = incs

INC_FILES = garbage.h \
			cube3d.h \
			get_next_line.h \
			parsing.h \
			raycast.h \
			events.h \
			mlx_utils.h \
			minimap.h \
			display.h \

INCLUDES =	mlx/mlx.h \
			${INC_FILES:%.h=${INC_DIR}/%.h} \

#OTHER

LIBFT_PATH = libft

NAME= cub3d

CC= gcc

FLAGS= -Wall -Wextra

LEAKS= -fsanitize=address -g3

${OBJ_DIR}%.o : ${SRCS_DIR}%.c	${INCLUDES}
				${CC} ${FLAGS} ${IMLX_LINUX} -c $< -o $@

all: Makefile makelib makemlx makedirs ${NAME}

${NAME}:	Makefile ${OBJS}
			${CC} ${FLAGS} ${OBJS} ${LMLX_LINUX} ${LIBFT_PATH}/libft.a -o ${NAME}

makelib:
			${MAKE} -C ${LIBFT_PATH}/ all

makemlx:
		${MAKE} -C mlx_linux/ all

makedirs:
			mkdir -p ${OBJ_DIR}${GNL}
			mkdir -p ${OBJ_DIR}${GARBAGE}
			mkdir -p ${OBJ_DIR}${RAYCAST}
			mkdir -p ${OBJ_DIR}${DEBUG}
			mkdir -p ${OBJ_DIR}${DISPLAY}
			mkdir -p ${OBJ_DIR}${PARSING}

clean:
			${MAKE} -C ${LIBFT_PATH}/ fclean
			rm -f ${OBJS}
			rm -rf objs

fclean:		clean
			rm -f ${NAME}

re:			fclean all

debug:		 Makefile makelib makemlx makedirs ${OBJS_DEBUG}
			${CC} ${OBJS_DEBUG} ${LEAKS} ${LMLX_LINUX} ${LIBFT_PATH}/libft.a -o ${NAME}

debugparsing: Makefile makelib makedirs ${OBJS_DEBPARSE}
			${CC} ${OBJS_DEBPARSE} ${LEAKS} ${LIBFT_PATH}/libft.a -o ${NAME}

PHONY= all clean fclean re
