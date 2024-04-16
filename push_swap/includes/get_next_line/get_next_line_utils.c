/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:08:30 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:32:32 by dwayenbo         ###   ########.fr       */
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

