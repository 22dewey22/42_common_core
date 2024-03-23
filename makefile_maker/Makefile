# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 08:19:01 by dwayenbo          #+#    #+#              #
#    Updated: 2024/02/19 17:50:25 by dwayenbo         ###   ########.fr        #
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
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

################################################################
#							LIBFT_ISH						   #
################################################################

# LIBDIR = libdw/
# LIBDW = $(LIBDIR)libdw.a
# LIB_HEADERS = $(LIBDIR)utils_headers/
# DWLIB_FLAGS = -I$(LIB_HEADERS)
# DWLIB_LIB = -L$(LIBDIR) -ldw

# ################################################################
# #							MLX								   #
# ################################################################

# MLX = $(MLX_DIR)libmlx_Linux.a
# MLX_DIR = mlx_linux/
# MLX_GZ = minilibx-linux.tgz
# MLX_FLAGS = -I/usr/include -I$(MLX_DIR) -g3
# MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz 

################################################################
#							PROJ							   #
################################################################

NAME = makefile_maker

MANDATORY = main.c parsing.c
BONUS = 

M_OBJS = $(addprefix srcs/, $(MANDATORY:.c=.o))
B_OBJS = $(M_OBJS) $(addprefix srcs/bonus/, $(BONUS:.c=.o))

DEPENDENCIES = 	$(patsubst %.o,%.d,$(M_OBJS)) $(patsubst %.o,%.d,$(B_OBJS))

HEADERS_DIR = headers/
HEADERS = -I$(HEADERS_DIR)

CFLAGS = -Wall -Werror -Wextra -MMD -MP

################################################################
#							RULES							   #
################################################################

%.o:%.c
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(HEADERS) $(DWLIB_FLAGS) -c $< -o $@

all: $(NAME)

$(LIBDW):
	@printf "$(BIGreen)COMPILING UTILS LIBRARY...\n$(BIWhite)"
	make -C $(LIBDIR)

$(MLX_DIR): $(MLX_GZ)
	@printf "$(BIBlue)EXTRACTING MLX LIBRARY...\n$(BIWhite)"
	tar -xf $(MLX_GZ) && mv $(MLX_GZ:.tgz=) $(MLX_DIR)

$(MLX): $(MLX_DIR)
	@printf "$(BIBlue)COMPILING MLX LIBRARY...\n$(BIWhite)"
	make -C mlx_linux

$(NAME): $(LIBDW) $(MLX) $(M_OBJS) 
	@printf "$(BIGreen)COMPILING BINARY : $(NAME)\n$(BIWhite)"
	$(CC) $(M_OBJS) $(MLX_LIB) $(DWLIB_LIB) -o $(NAME)

re: fclean all

clean: clean_dw
	rm -f $(M_OBJS) $(B_OBJS) $(DEPENDENCIES)

fclean: clean fclean_dw
	rm -f $(NAME)

clean_dw:
	@printf "$(BIRed)REMOVING PERSONNAL LIB OBJS AND DEPS\n$(BIWhite)"
	make -C $(LIBDIR) clean
	
fclean_dw:
	@printf "$(BIRed)REMOVING PERSONNAL LIB, ITS OBJS AND ITS DEPS\n$(BIWhite)"
	make -C $(LIBDIR) fclean
	@printf "$(BIRed)REMOVING MLX\n$(BIWhite)"
	rm -rf $(MLX_DIR)

.PHONY: all clean fclean bonus clean_dw fclean_dw re

-include $(DEPENDENCIES)