
NAME = libftprintf.a

SRCS = ft_printf.c ft_util_printf.c ft_util_printf2.c ft_print_printf.c ft_parsing_printf.c 

OBJS = $(addprefix ${INCLUDES}, ${SRCS:.c=.o}) ${LIBFT_OBJS} ${LIBFT_BONUS_OBJS} 

HEADERS = headers/

INCLUDES = includes/ft_printf/

LIBFT_SRCS =	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
    		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_atoi.c \
		ft_strdup.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c \
		ft_striteri.c ft_strmapi.c ft_itoa.c ft_strjoin.c ft_strtrim.c ft_split.c ft_is_charset.c \
		ft_get_hex_len.c ft_print_hex_fd.c ft_print_uint_fd.c ft_get_uint_len.c ft_get_int_len.c \
		ft_signof.c \

LIBFT_OBJS = $(addprefix ${INCLUDES_LIBFT}, ${LIBFT_SRCS:.c=.o})

INCLUDES_LIBFT = includes/libft/

LIBFT_BONUS = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

LIBFT_BONUS_OBJS = $(addprefix ${INCLUDES_LIBFT}, ${LIBFT_BONUS:.c=.o})

CC = cc 

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
	ar rcs ${NAME} ${OBJS} 

bonus: all

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

test: ${NAME}
	@clear
	@${CC} -g3 test.c -I ${HEADERS} -L. -lftprintf
	@./a.out | cat -e
	@rm a.out

.PHONY:all re clean fclean bonus
