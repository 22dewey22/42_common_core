/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:16:25 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/14 15:10:56 by dwayenbo         ###   ########.fr       */
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
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_max(int a, int b);
int		ft_dec_len(int n);
char	*ft_pathjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
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
char	*ft_strjoin(const char *s1, const char *s2);
#endif
