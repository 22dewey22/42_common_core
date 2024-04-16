/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:16:25 by david             #+#    #+#             */
/*   Updated: 2023/12/02 22:32:59 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STUFF_H
# define LIBFT_STUFF_H
# include <stdlib.h>
# include <unistd.h>

int		ft_ischarset(char c, char *set);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_signof(int n);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_max(int a, int b);
int		ft_dec_len(int n);
/******************ft_ato.c***************/
long	ft_atol(char *str);
int		ft_atoi(char *str);
/*****************************************/
int		ft_strchr(const char *s, int c);
void	ft_strncpy(char *dest, char *src, int len);
char	**ft_split(char const *s, char c);
/**************ft_free_split.c************/
int		ft_free_split(char **split, int error);
int		ft_get_split_len(char **split);

#endif