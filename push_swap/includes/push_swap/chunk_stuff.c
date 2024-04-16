/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:33:30 by david             #+#    #+#             */
/*   Updated: 2023/12/03 08:33:18 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_find_chunk(t_stack **stack_a, int reverse, int max_value)
{
	int		output;
	t_stack	*current;

	current = *stack_a;
	if (ps_get_stack_len(stack_a) <= 3)
		return (-1);
	output = 0;
	while (current->value > max_value && current->next != *stack_a)
	{
		output++;
		current = current->next;
	}
	if (current->value > max_value)
		return (-1);
	if (reverse == 0)
		return (output);
	else
		return (ps_get_stack_len(stack_a) - output);
}

void	ps_chunk_cutter(t_stack **stack_c, t_stack **stack_d, int chunk_count)
{
	int		i;
	int		j;
	t_stack	*current;

	if (chunk_count <= 10)
		chunk_count = 1;
	else if (chunk_count <= 100)
		chunk_count = LOW_CHUNK;
	else
		chunk_count = BIG_CHUNK;
	i = 1;
	j = 0;
	current = *stack_c;
	while (i <= chunk_count + 1)
	{
		while (j < ps_get_stack_len(stack_c) / chunk_count * i
			&& j < ps_get_stack_len(stack_c) - 1)
		{
			current = current->next;
			j++;
		}
		ps_addback(stack_d, current->value);
		i++;
	}
}

void	ps_push_chunk(t_stack **stack_a, t_stack **stack_b, int max_value)
{
	int	roll;
	int	roll_reverse;
	int	i;

	roll = ps_find_chunk(stack_a, 0, max_value);
	roll_reverse = ps_find_chunk(stack_a, 1, max_value);
	while (roll != -1)
	{
		i = 0;
		if (roll <= roll_reverse)
		{
			while (i++ < roll)
				rx(stack_a, 0, 'a', 1);
		}
		else
		{
			while (i++ < roll_reverse)
				rrx(stack_a, 0, 'a', 1);
		}
		px(stack_a, stack_b, 'b', 1);
		roll = ps_find_chunk(stack_a, 0, max_value);
		roll_reverse = ps_find_chunk(stack_a, 1, max_value);
	}
}

void	ps_transfer_chunks(t_stack **stack_a, t_stack **stack_b,
		t_stack **stack_c, t_stack **stack_d)
{
	t_stack	*buf;

	ps_chunk_cutter(stack_c, stack_d, ps_get_stack_len(stack_c));
	buf = *stack_d;
	while (buf->next != *stack_d && ps_get_stack_len(stack_a) > 3)
	{
		ps_push_chunk(stack_a, stack_b, buf->value);
		buf = buf->next;
	}
	while (ps_get_stack_len(stack_a) > 3)
		px(stack_a, stack_b, 'b', 1);
}
