/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:25:45 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/31 08:42:15 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_conv
{
	char	flag;
	char	conv;
	char	length;
	char	hash;
	char	sign;
	int		width;
	int		precision;
	int		var_len;
	int		end_len;
}			t_conv;
// ft_printf.c
int			ft_printf(const char *s, ...);
// ft_util_printf.c
int			printf_atoi_lite(char *str, int *index);
void		printf_putstr(t_conv to_print, char *str, int *count);
t_conv		printf_init_conf(void);
int			printf_get_len(int var, t_conv to_print);
int			printf_getuint_len(unsigned int var, t_conv to_print,
				int base_size);
// ft_util_printf2.c
void		printf_putuint(unsigned int var, t_conv to_print, char *base);
void		printf_putalign(t_conv to_print, int *count);
// ft_print_printf.c
void		printf_print_int(t_conv to_print, va_list args, int *count);
void		printf_print_uint(t_conv to_print, va_list args, int *count,
				char *base);
void		printf_print_char(t_conv to_print, va_list args, int *count);
void		printf_print_str(t_conv to_print, va_list args, int *count);
void		printf_print_ptr(t_conv to_print, va_list args, int *count);
// ft_print_printf2.c
// ft_parsing_printf.c
void		printf_parse_conf(t_conv to_print, va_list args, int *count);
void		printf_parse_width(va_list args, t_conv *to_print, char *str,
				int *index);
void		printf_parse_precision(va_list args, t_conv *to_print, char *str,
				int *index);
void		printf_parse_entry(va_list args, char *str, int *index, int *count);

#endif
