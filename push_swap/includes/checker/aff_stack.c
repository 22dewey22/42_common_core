/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 08:52:22 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/03 09:38:43 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_aff_stacks(t_stack **stack_a, t_stack **stack_b, char first_char,
		char second_char)
{
	ps_print_stack(stack_a, first_char);
	ps_print_stack(stack_b, second_char);
}

void	ps_print_stack(t_stack **stack_a, char first_char)
{
	t_stack	*current_a;

	current_a = *stack_a;
	ft_printf_fd(1, "%c => ", first_char);
	if (current_a)
	{
		ft_printf_fd(1, "%c%d%c", '[', current_a->value, ']');
		while (current_a->next != *stack_a)
		{
			current_a = current_a->next;
			ft_printf_fd(1, "%c%d%c", '[', current_a->value, ']');
		}
	}
	else
		ft_printf_fd(1, "Empty");
	ft_printf_fd(1, "\n");
}
