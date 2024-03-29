# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 08:19:01 by dwayenbo          #+#    #+#              #
#    Updated: 2024/03/29 09:49:45 by dwayenbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################
#							COLORS							   #
################################################################
# Bold High Intensity
BIBlack=\033[1;90m
BIRed=\033[1;91m
BIGreen=\033[1;92m
BIYellow=\033[1;93m
BIBlue=\033[1;94m
BIPurple=\033[1;95m
BICyan=\033[1;96m
BIWhite=\033[1;97m
# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;35m
BCyan=\033[1;36m
BWhite=\033[1;37m
# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

################################################################
#							LIBFT_ISH						   #
################################################################

LIBDIR = libdw/
LIBDW = $(LIBDIR)libdw.a
LIB_HEADERS = $(LIBDIR)utils_headers/
DWLIB_FLAGS = -I$(LIB_HEADERS)
DWLIB_LIB = -L$(LIBDIR) -ldw

################################################################
#							MLX								   #
################################################################

MLX = $(MLX_DIR)libmlx_Linux.a
MLX_DIR = mlx_linux/
MLX_GZ = minilibx-linux.tgz
MLX_FLAGS = -I/usr/include -I$(MLX_DIR) -g3
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz 

################################################################
#							PROJ							   #
################################################################

NAME = fdf

MANDATORY = arg_parser.c \
			arg_parser_utils.c \
			colors.c \
			draw.c \
			hooks.c \
			init_graph.c \
			init_graph_utils.c \
			init_prog.c \
			main.c \
			mouse.c \
			rendu.c \
			rotations.c \
			translations.c \
			
MANDATORY_V4 = 	srcs/v4/arg_parser_v4.c \
				srcs/v4/arg_parser_utils.c \
				srcs/v4/main.c \
				srcs/v4/file_reader.c \
				srcs/v4/calc_utils.c \
				srcs/v4/map_calc.c \
				srcs/v4/draw.c \
				srcs/v4/colors.c

BONUS = 

V4_OBJS = $(MANDATORY_V4:.c=.o)

M_OBJS = $(addprefix srcs/, $(MANDATORY:.c=.o))
B_OBJS = $(M_OBJS) $(addprefix srcs/bonus/, $(BONUS:.c=.o))

DEPENDENCIES = 	$(patsubst %.o,%.d,$(M_OBJS)) $(patsubst %.o,%.d,$(V4_OBJS)) $(patsubst %.o,%.d,$(B_OBJS))

HEADERS = -Iheaders/

CFLAGS = -Wall -Werror -Wextra -MMD -MP 

################################################################
#							RULES							   #
################################################################

%.o:%.c
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(HEADERS) $(DWLIB_FLAGS) -c $< -o $@

all: $(NAME)

$(LIBDW):
	@printf "$(BIGreen)COMPILING UTILS LIBRARY...\n$(White)"
	make -C $(LIBDIR)

$(MLX_DIR): $(MLX_GZ)
	@printf "$(BIBlue)EXTRACTING MLX LIBRARY...\n$(White)"
	tar -xf $(MLX_GZ) && mv $(MLX_GZ:.tgz=) $(MLX_DIR)

$(MLX): $(MLX_DIR)
	@printf "$(BIBlue)COMPILING MLX LIBRARY...\n$(White)"
	make -C mlx_linux

$(NAME): $(LIBDW) $(MLX) $(M_OBJS) 
	@printf "$(BIGreen)COMPILING BINARY : $(NAME)\n$(White)"
	$(CC) $(CFLAGS) $(M_OBJS) $(MLX_LIB) $(DWLIB_LIB) -o $(NAME)

test:	$(MLX) $(LIBDW) $(V4_OBJS)
		$(CC) $(CFLAGS) $(V4_OBJS) $(MLX_LIB) $(DWLIB_LIB) -o v4_fdf
		
re: fclean all

clean: clean_dw
	rm -f $(M_OBJS) $(B_OBJS) $(DEPENDENCIES) $(V4_OBJS)

fclean: clean fclean_dw
	rm -f $(NAME)  v4_fdf

clean_dw:
	@printf "$(BIRed)REMOVING PERSONNAL LIB OBJS AND DEPS\n$(White)"
	make -C $(LIBDIR) clean
	
fclean_dw:
	@printf "$(BIRed)REMOVING PERSONNAL LIB, ITS OBJS AND ITS DEPS\n$(White)"
	make -C $(LIBDIR) fclean
	@printf "$(BIRed)REMOVING MLX\n$(White)"
	rm -rf $(MLX_DIR)

.PHONY: all clean fclean bonus clean_dw fclean_dw re

-include $(DEPENDENCIES)