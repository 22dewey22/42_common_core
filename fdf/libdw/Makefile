# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 06:22:14 by dwayenbo          #+#    #+#              #
#    Updated: 2024/03/11 15:38:20 by dwayenbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libdw.a

AR = 		ar rcs
CC = 		cc
DEPFLAGS = 	-MD -MP
CFLAGS = 	-Wall -Werror -Wextra $(DEPFLAGS)

HEADERS = 	utils_headers/
PRINTF =	$(addprefix ft_printf_fd/, ft_parsing_printf.c ft_print_printf.c ft_printf.c ft_util_printf.c ft_util_printf2.c)
GNL =		$(addsuffix .c, $(addprefix get_next_line/, get_next_line get_next_line_utils))
LIBFT = 	$(addsuffix .c, $(addprefix libft_stuff/,\
									ft_ato ft_dec_len ft_free_split ft_get_hex_len ft_ischarset ft_isdigit ft_max ft_pathjoin\
									ft_print_hex_fd ft_putchar_fd ft_putstr_fd ft_signof ft_split ft_strchr ft_strcmp ft_strdup\
									ft_strjoin ft_strlen ft_strncmp ft_strncpy))

OBJS = 		$(PRINTF:.c=.o) $(GNL:.c=.o) $(LIBFT:.c=.o)
DEPS = 		$(OBJS:.o=.d)

%.o:%.c
			$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^
	
clean:
			rm -f $(OBJS) $(DEPS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

-include $(DEPS)