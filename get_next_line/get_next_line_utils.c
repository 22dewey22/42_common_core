/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:08:30 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/11/01 12:44:49 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_list_del(t_list *list_start)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = list_start;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->str)
			free(ptr->str);
		free(ptr);
		ptr = tmp;
	}
}

int	gnl_init_list(t_list **list_start)
{
	*list_start = (t_list *)malloc(sizeof(t_list));
	if (*list_start == 0)
		return (-1);
	(*list_start)->str = 0;
	(*list_start)->len = 0;
	(*list_start)->next = 0;
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (p[i])
	{
		if (p[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strncpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
