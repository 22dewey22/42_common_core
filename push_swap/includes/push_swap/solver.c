/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:27:07 by david             #+#    #+#             */
/*   Updated: 2023/12/03 08:32:51 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_solve(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_c;
	t_stack	*stack_d;
	t_stack	*tmp;

	stack_d = 0;
	stack_c = ps_sort_stack(*stack_a);
	if (ps_stack_cmp(stack_a, &stack_c) == 0)
		return (ps_destroy_list(&stack_c, 0));
	tmp = *stack_a;
	while (tmp->next != *stack_a)
	{
		tmp = tmp->next;
		if (ps_stack_cmp(&tmp, &stack_c) == 0)
		{
			ps_final_roll(stack_a, &stack_c);
			ps_destroy_stacks(stack_a, stack_b, &stack_c, &stack_d);
			return (0);
		}
	}
	ps_transfer_chunks(stack_a, stack_b, &stack_c, &stack_d);
	ps_solve_three(stack_a);
	ps_flush_b(stack_a, stack_b);
	ps_final_roll(stack_a, &stack_c);
	ps_destroy_stacks(stack_a, stack_b, &stack_c, &stack_d);
	return (0);
}

void	ps_final_roll(t_stack **stack_a, t_stack **stack_c)
{
	int		i;
	int		len;
	t_stack	*current;

	len = ps_get_stack_len(stack_a);
	i = 0;
	current = *stack_a;
	while (ps_stack_cmp(&current, stack_c))
	{
		i++;
		current = current->next;
	}
	while (ps_stack_cmp(stack_a, stack_c))
	{
		if (i > len / 2)
			rrx(stack_a, 0, 'a', 1);
		else
			rx(stack_a, 0, 'a', 1);
	}
}
