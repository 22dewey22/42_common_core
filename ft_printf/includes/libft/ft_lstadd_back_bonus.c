/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:55:05 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/16 09:07:05 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!current)
		*lst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
