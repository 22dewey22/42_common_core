# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:31 by dwayenbo             #+#    #+#              #
#    Updated: 2024/02/05 09:10:04 by dwayenbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PX = pipex

PX_BONUS = pipex_bonus

HEADERS =  headers/

INCLUDES = srcs/
UTILS = $(INCLUDES)utils/

CC = cc 

DEPFLAGS = -MP -MMD
CFLAGS = -Wall -Wextra -Werror -g3 ${DEPFLAGS}

LFT_SRCS = 		$(addprefix $(UTILS)libft_stuff/, ft_ato.c ft_get_hex_len.c ft_ischarset.c ft_isdigit.c  ft_print_hex_fd.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_signof.c ft_strchr.c ft_strlen.c ft_strncpy.c \
				ft_split.c ft_free_split.c ft_strdup.c ft_strcmp.c ft_max.c ft_dec_len.c ft_strncmp.c ft_pathjoin.c \
				ft_strjoin.c)

GNL_SRCS = 		$(addprefix $(UTILS)get_next_line/, get_next_line.c get_next_line_utils.c)

PRINTF_SRCS = 	$(addprefix $(UTILS)ft_printf_fd/,	ft_parsing_printf.c ft_print_printf.c ft_printf.c ft_util_printf.c \
				ft_util_printf2.c)

UTILS_OBJS = 	${PRINTF_SRCS:.c=.o} ${GNL_SRCS:.c=.o} ${LFT_SRCS:.c=.o}

PX_SRCS = 		cmds_exec.c cmds_parsing.c general_parsing.c init.c misc.c processes.c 
M_SRCS = 		main.c parsing_mandatory.c
B_SRCS = 		main_bonus.c parsing_bonus.c here_doc_bonus.c

PX_OBJS = 		${UTILS_OBJS} $(addprefix ${INCLUDES}, ${PX_SRCS:.c=.o} ${M_SRCS:.c=.o})

BONUS_OBJS = 	${UTILS_OBJS} $(addprefix ${INCLUDES}, ${PX_SRCS:.c=.o} ${B_SRCS:.c=.o})

DEPENDENCIES = 	$(patsubst %.o,%.d,${PX_OBJS}) $(patsubst %.o,%.d,${BONUS_OBJS})

all: ${PX}	 

%.o: %.c 
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${PX}: ${PX_OBJS} 
	${CC} ${CFLAGS} $^ -o $@
${PX_BONUS}: ${BONUS_OBJS}
		${CC} ${CFLAGS} $^ -o $@

bonus: ${PX_BONUS}

clean:
	rm -f ${PX_OBJS} ${BONUS_OBJS} ${DEPENDENCIES}

fclean: clean
	rm -f ${PX} ${PX_BONUS}
	rm -rf logs

re: fclean all

.PHONY:all re clean fclean bonus 

test_m: all
	@./pipex_test_m.sh
test_b: bonus
	@./pipex_test_b.sh

-include $(DEPENDENCIES)