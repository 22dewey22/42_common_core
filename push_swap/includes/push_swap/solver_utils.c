/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 07:50:30 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/03 08:35:44 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_flush_b(t_stack **stack_a, t_stack **stack_b)
{
	t_score	best;
	t_score	now;
	int		current_pos;
	t_stack	*current;

	while (ps_get_stack_len(stack_b) > 0)
	{
		current = *stack_b;
		current_pos = 0;
		best = ps_get_score_flush_b(stack_a, stack_b, current_pos);
		while (current->next != *stack_b)
		{
			current = current->next;
			current_pos++;
			now = ps_get_score_flush_b(stack_a, stack_b, current_pos);
			if (now.total_actions < best.total_actions)
				best = now;
		}
		ps_push_good_pos(stack_a, stack_b, best);
	}
}

t_score	ps_get_score_flush_b(t_stack **stack_a, t_stack **stack_b, int position)
{
	t_score	output;

	output.actual_pos = position;
	output.good_pos = ps_get_good_pos(stack_a, stack_b, position);
	output.total_actions = 0;
	output = ps_process_output(stack_a, stack_b, output);
	return (output);
}

int	ps_get_good_pos(t_stack **stack_a, t_stack **stack_b, int position)
{
	t_stack	*current;

	current = *stack_b;
	while (position)
	{
		current = current->next;
		position--;
	}
	if (ps_val_is_max(stack_a, current->value) || ps_val_is_min(stack_a,
			current->value))
		return (ps_get_minmax_pos(stack_a));
	return (ps_get_intermediate_pos(stack_a, current->value));
}

void	ps_push_good_pos(t_stack **stack_a, t_stack **stack_b, t_score best)
{
	ps_roll_same_side(stack_a, stack_b, &best);
	ps_roll_both_side(stack_a, stack_b, &best);
	px(stack_a, stack_b, 'a', 1);
}

t_score	ps_process_output(t_stack **stack_a, t_stack **stack_b, t_score output)
{
	if (output.good_pos > ps_get_stack_len(stack_a) / 2)
		output.good_pos = output.good_pos - ps_get_stack_len(stack_a);
	if (output.actual_pos > ps_get_stack_len(stack_b) / 2)
		output.actual_pos = output.actual_pos - ps_get_stack_len(stack_b);
	if (ft_signof(output.actual_pos) == ft_signof(output.good_pos))
	{
		output.total_actions = ft_max(ft_signof(output.actual_pos)
				* output.actual_pos, ft_signof(output.good_pos)
				* output.good_pos);
	}
	else
		output.total_actions = ft_signof(output.actual_pos) * output.actual_pos
			+ ft_signof(output.good_pos) * output.good_pos;
	return (output);
}
