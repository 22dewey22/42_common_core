/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:41:57 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/03 08:35:33 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_solve_three(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (ps_get_stack_len(stack_a) <= 2)
		return (ps_solve_two(stack_a));
	first = *stack_a;
	second = first->next;
	third = second->next;
	ps_actions_three(stack_a, first, second, third);
}

void	ps_actions_three(t_stack **stack_a, t_stack *first, t_stack *second,
		t_stack *third)
{
	if (ps_val_is_max(stack_a, first->value))
	{
		rx(stack_a, 0, 'a', 1);
		if (second->value > third->value)
			sx(stack_a, 0, 'a', 1);
	}
	else if (ps_val_is_min(stack_a, first->value)
		&& second->value > third->value)
	{
		sx(stack_a, 0, 'a', 1);
		rx(stack_a, 0, 'a', 1);
	}
	else if (!ps_val_is_min(stack_a, first->value) && !ps_val_is_max(stack_a,
			first->value))
	{
		if (second->value < third->value)
			sx(stack_a, 0, 'a', 1);
		else
			rrx(stack_a, 0, 'a', 1);
	}
}

void	ps_solve_two(t_stack **stack_a)
{
	if (ps_get_stack_len(stack_a) <= 1)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		return (rrx(stack_a, 0, 'a', 1));
}
