/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:04:08 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:20:50 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_roll(t_stack **first)
{
	*first = (*first)->next;
}

void	ps_swap(t_stack **first)
{
	t_stack	*tmp_first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*current;

	if (*first == 0)
		return ;
	if ((*first)->next == *first)
		return ;
	tmp_first = *first;
	second = (*first)->next;
	third = second->next;
	second->next = tmp_first;
	tmp_first->next = third;
	*first = second;
	current = tmp_first;
	while (current->next != tmp_first)
		current = current->next;
	current->next = *first;
}
