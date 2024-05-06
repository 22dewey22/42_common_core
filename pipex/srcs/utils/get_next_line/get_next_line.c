/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:19:19 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/14 10:12:57 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;
	int			nl_pos;
	t_list		*list_start;

	nl_pos = ft_strchr(buffer, '\n');
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (gnl_init_list(&list_start) == -1)
		return (0);
	if (nl_pos >= 0)
	{
		gnl_add(list_start, buffer, nl_pos + 1);
		ft_strncpy(buffer, &buffer[nl_pos + 1], BUFFER_SIZE);
		output = gnl_cat_list(list_start, 0, 0);
		gnl_list_del(list_start);
		return (output);
	}
	gnl_add(list_start, buffer, ft_strlen(buffer));
	ft_strncpy(buffer, "", BUFFER_SIZE);
	gnl_read(list_start, buffer, fd);
	output = gnl_cat_list(list_start, 0, 0);
	gnl_list_del(list_start);
	return (output);
}

void	gnl_read(t_list *list_start, char *buffer, int fd)
{
	int	read_bytes;
	int	nl_pos;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return ;
	while (read_bytes)
	{
		buffer[read_bytes] = 0;
		nl_pos = ft_strchr(buffer, '\n');
		if (nl_pos >= 0)
		{
			gnl_add(list_start, buffer, nl_pos + 1);
			ft_strncpy(buffer, &buffer[nl_pos + 1], BUFFER_SIZE);
			return ;
		}
		gnl_add(list_start, buffer, read_bytes);
		ft_strncpy(buffer, "", BUFFER_SIZE);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
}

void	gnl_add(t_list *list_start, char *buffer, int len)
{
	t_list	*ptr;

	ptr = list_start;
	if (len == 0)
		return ;
	if (list_start->len <= -1)
		return ;
	if (list_start->len == 0)
		return (gnl_insert_list(ptr, buffer, len));
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = (t_list *)malloc(sizeof(t_list));
	if (!ptr->next)
	{
		list_start->len = -2;
		return ;
	}
	ptr = ptr->next;
	return (gnl_insert_list(ptr, buffer, len));
}

void	gnl_insert_list(t_list *pos, char *buffer, int len)
{
	pos->str = (char *)malloc(sizeof(char) * (len + 1));
	if (!pos->str)
		pos->len = -1;
	else
	{
		ft_strncpy(pos->str, buffer, len);
		pos->next = 0;
		pos->len = len;
	}
}

char	*gnl_cat_list(t_list *list_start, int out_len, int j)
{
	char	*output;
	t_list	*ptr;

	ptr = list_start;
	while (ptr)
	{
		if (ptr->len <= 0)
			return (0);
		out_len += ptr->len;
		ptr = ptr->next;
	}
	if (out_len <= 0)
		return (0);
	output = (char *)malloc(sizeof(char) * (out_len + 1));
	if (!output)
		return (0);
	ptr = list_start;
	while (ptr)
	{
		ft_strncpy(&output[j], ptr->str, ptr->len);
		j += ptr->len;
		ptr = ptr->next;
	}
	return (output);
}
