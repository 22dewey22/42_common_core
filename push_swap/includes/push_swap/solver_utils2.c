/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:43:45 by david             #+#    #+#             */
/*   Updated: 2023/12/03 08:36:08 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_get_minmax_pos(t_stack **stack_a)
{
	int		output;
	t_stack	*current;

	output = 0;
	current = *stack_a;
	while (ps_val_is_min(stack_a, current->value) != 1)
	{
		output++;
		current = current->next;
	}
	return (output);
}

int	ps_get_intermediate_pos(t_stack **stack_a, int value)
{
	int		output;
	t_stack	*current;

	output = 1;
	current = *stack_a;
	while (!(current->value < value && current->next->value > value))
	{
		output++;
		current = current->next;
	}
	if (output == ps_get_stack_len(stack_a))
	{
		return (0);
	}
	return (output);
}

void	ps_roll_same_side(t_stack **stack_a, t_stack **stack_b, t_score *best)
{
	if (ft_signof(best->actual_pos) == ft_signof(best->good_pos))
	{
		while (best->actual_pos && best->good_pos)
		{
			if (ft_signof(best->actual_pos) < 0)
				rrx(stack_a, stack_b, 'r', 1);
			else
				rx(stack_a, stack_b, 'r', 1);
			best->actual_pos -= ft_signof(best->actual_pos);
			best->good_pos -= ft_signof(best->good_pos);
		}
	}
}

void	ps_roll_both_side(t_stack **stack_a, t_stack **stack_b, t_score *best)
{
	while (best->actual_pos || best->good_pos)
	{
		if (best->actual_pos < 0)
			rrx(stack_a, stack_b, 'b', 1);
		else if (best->actual_pos > 0)
			rx(stack_a, stack_b, 'b', 1);
		if (best->good_pos < 0)
			rrx(stack_a, stack_b, 'a', 1);
		else if (best->good_pos > 0)
			rx(stack_a, stack_b, 'a', 1);
		best->actual_pos -= ft_signof(best->actual_pos);
		best->good_pos -= ft_signof(best->good_pos);
	}
}
