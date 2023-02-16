SRCS_DIR = srcs/

GARBAGE = garbage/

PARSING = parsing/

GNL = getnextline/

RAYCAST = raycast/

DISPLAY = display/

SRCS = main.c

SRCS_GARBAGE = 	garbagecoll.c \
				garbage_utils.c \
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
				vectors2.c \
				raycast.c \
				raycast_utils.c \
				stripe.c \

SRCS_DISPLAY = 	display.c \
				display_utils.c \
				move.c \
				move_utils.c \
				mlx_utils.c \
				minimap.c \
				minimap_utils.c \
				initdisplay.c \
				loop.c \
				openspritewall.c \
				spritewall.c \
				spritewallutils.c \
				shading.c \
				drawcf.c \
				drawcf_utils.c \
				keys.c \

#OBJS

OBJ_DIR = objs/

OBJS = 	${SRCS_GARBAGE_ABS:%.c=${OBJ_DIR}%.o} \
		${SRCS_GNL_ABS:%.c=${OBJ_DIR}%.o} \
		${SRCS_RAYCAST_ABS:%.c=${OBJ_DIR}%.o} \
		${SRCS_DISPLAY_ABS:%.c=${OBJ_DIR}%.o} \
		${SRCS_PARSING_ABS:%.c=${OBJ_DIR}%.o} \
		${SRCS:%.c=${OBJ_DIR}%.o}

OTHER =	${SRCS/GARBAGE:%.c=${OBJ_DIR}/${GARBAGE}%.o} \
		${SRCS/PARSING:%.c=${OBJ_DIR}/${PARSING}%.o} \
		${SRCS/GNL:%.c=${OBJ_DIR}/${GNL}%.o} \
		${SRCS/RAYCAST:%.c=${OBJ_DIR}/${RAYCAST}%.o} \

SRCS_GARBAGE_ABS = ${SRCS_GARBAGE:%.c=${GARBAGE}%.c}

SRCS_GNL_ABS = ${SRCS_GNL:%.c=${GNL}%.c}

SRCS_RAYCAST_ABS = ${SRCS_RAYCAST:%.c=${RAYCAST}%.c}

SRCS_DISPLAY_ABS = ${SRCS_DISPLAY:%.c=${DISPLAY}%.c}

SRCS_PARSING_ABS = ${SRCS_PARSING:%.c=${PARSING}%.c}

#MLX

IMLX_MACOS = -Imlx

LMLX_MACOS = -Lmlx -lmlx -framework OpenGL -framework AppKit

IMLX_LINUX = -I/usr/include -I mlx -O3

LMLX_LINUX = -L mlx -L /usr/lib -lmlx -lmlx_Linux -lXext -lX11 -lm

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
			vectors.h \

INCLUDES = ${INC_FILES:%.h=${INC_DIR}/%.h} \

#OTHER

LIBFT_PATH = libft

LIBFT = ${LIBFT_PATH}/libft.a

MLX = mlx/libmlx_Linux.a

NAME= cub3d

CC= gcc

FLAGS= -Wall -Wextra -Werror -g

LEAKS= -fsanitize=address -g3

${OBJ_DIR}%.o : ${SRCS_DIR}%.c	${INCLUDES}
				${CC} ${FLAGS} ${IMLX_LINUX} -c $< -o $@

all: Makefile makelib makemlx makedirs ${NAME}

${NAME}:	${OBJS} ${LIBFT} ${MLX}
			${CC} ${OBJS} ${LMLX_LINUX} -L ${LIBFT_PATH} -lft -o ${NAME}

makelib:
			${MAKE} -C ${LIBFT_PATH}/ all

makemlx:
			${MAKE} -C mlx/ all

makedirs:
			@mkdir -p ${OBJ_DIR}${GNL}
			@mkdir -p ${OBJ_DIR}${GARBAGE}
			@mkdir -p ${OBJ_DIR}${RAYCAST}
			@mkdir -p ${OBJ_DIR}${DISPLAY}
			@mkdir -p ${OBJ_DIR}${PARSING}

clean:
			${MAKE} -C ${LIBFT_PATH}/ fclean
			${MAKE} -C mlx/ clean
			rm -f ${OBJS}
			rm -rf objs

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re makelib makemlx makedirs
