/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:02:55 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:31:39 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a == 0)
		return ;
	tmp = *stack_a;
	ps_pop(stack_a);
	ps_push(stack_b, tmp);
}

void	ps_push(t_stack **first, t_stack *to_push)
{
	t_stack	*current;

	if (*first == 0)
	{
		*first = to_push;
		to_push->next = to_push;
		return ;
	}
	to_push->next = *first;
	current = *first;
	while (current->next != to_push->next)
		current = current->next;
	current->next = to_push;
	*first = to_push;
}

void	ps_pop(t_stack **first)
{
	t_stack	*tmp;
	t_stack	*current;

	if ((*first)->next == *first)
	{
		*first = 0;
		return ;
	}
	current = *first;
	tmp = *first;
	*first = (*first)->next;
	while (current->next != tmp)
		current = current->next;
	current->next = *first;
}

void	ps_roll_reverse(t_stack **first)
{
	t_stack	*current;

	if (*first == 0)
		return ;
	current = *first;
	while (current->next != *first)
		current = current->next;
	*first = current;
}
