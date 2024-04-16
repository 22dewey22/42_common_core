# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 23:39:31 by david             #+#    #+#              #
#    Updated: 2023/12/03 12:26:36 by dwayenbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PS = push_swap

CHECKER = checker

LFT_SRCS = 	ft_ato.c ft_get_hex_len.c ft_ischarset.c ft_isdigit.c  ft_print_hex_fd.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_signof.c ft_strchr.c ft_strlen.c ft_strncpy.c \
			ft_split.c ft_free_split.c ft_strcmp.c ft_max.c ft_dec_len.c
			
LFT_OBJS = $(addprefix ${INCLUDES}, $(addprefix libft_stuff/,  ${LFT_SRCS:.c=.o})) 

GNL_SRCS = get_next_line.c get_next_line_utils.c

GNL_OBJS = $(addprefix ${INCLUDES}, $(addprefix get_next_line/,  ${GNL_SRCS:.c=.o})) 

PRINTF_SRCS = 	ft_parsing_printf.c ft_print_printf.c ft_printf.c ft_util_printf.c \
				ft_util_printf2.c

PRINTF_OBJS = $(addprefix ${INCLUDES}, $(addprefix ft_printf_fd/,  ${PRINTF_SRCS:.c=.o})) 

PS_SRCS = 	aff_functions.c chunk_stuff.c list_utils.c list_utils2.c parsing.c parsing2.c solver.c solver_three.c \
			solver_utils.c solver_utils2.c stack_actions.c stack_actions2.c tree_utils.c 
			

PS_OBJS = ${PRINTF_OBJS} ${LFT_OBJS} $(addprefix ${INCLUDES}, $(addprefix push_swap/, ${PS_SRCS:.c=.o})) includes/push_swap/ps_main.o

CHECKER_SRCS = checker_main.c aff_stack.c

CHECKER_OBJS = ${PRINTF_OBJS} ${LFT_OBJS} $(addprefix ${INCLUDES}, $(addprefix push_swap/, ${PS_SRCS:.c=.o})) ${GNL_OBJS} $(addprefix ${INCLUDES}, $(addprefix checker/, ${CHECKER_SRCS:.c=.o}))

HEADERS = headers/

INCLUDES = includes/

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g3

all: ${PS}	 

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${PS}: ${PS_OBJS}
	${CC} ${CFLAGS} ${PS_OBJS} -o ${PS}

${CHECKER}: ${CHECKER_OBJS} 
	${CC} ${CFLAGS} ${CHECKER_OBJS} -o ${CHECKER}

bonus: ${CHECKER}

clean:
	rm -f ${CHECKER_OBJS} ${PS_OBJS}

fclean: clean
	rm -f ${PS} ${CHECKER}

re: fclean all

.PHONY:all re clean fclean bonus 
