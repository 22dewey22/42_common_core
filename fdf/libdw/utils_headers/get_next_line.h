/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:51:06 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/27 08:10:41 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif
# include <fcntl.h>
# include <libft_stuff.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				len;
	char			*str;
	struct s_list	*next;
}					t_list;
// get_next_line.c
char				*get_next_line(int fd);
void				gnl_read(t_list *list_start, char *buffer, int fd);
void				gnl_add(t_list *list_start, char *buffer, int len);
void				gnl_insert_list(t_list *pos, char *buffer, int len);
char				*gnl_cat_list(t_list *list_start, int out_len, int j);

// get_next_line_utils.c
int					gnl_init_list(t_list **list_start);
void				gnl_list_del(t_list *list_start);
int					ft_strlen(char *s);

#endif
