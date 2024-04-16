/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:52:23 by david             #+#    #+#             */
/*   Updated: 2023/12/03 09:32:03 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	px(t_stack **stack_a, t_stack **stack_b, char x, int to_print)
{
	if (x == 'b')
		ps_push_a_to_b(stack_a, stack_b);
	if (x == 'a')
		ps_push_a_to_b(stack_b, stack_a);
	if (to_print)
		ft_printf_fd(1, "p%c\n", x);
}

void	rx(t_stack **stack_a, t_stack **stack_b, char x, int to_print)
{
	if (x == 'a')
		ps_roll(stack_a);
	if (x == 'b')
		ps_roll(stack_b);
	if (x == 'r')
	{
		ps_roll(stack_b);
		ps_roll(stack_a);
	}
	if (to_print)
		ft_printf_fd(1, "r%c\n", x);
}

void	rrx(t_stack **stack_a, t_stack **stack_b, char x, int to_print)
{
	if (x == 'a')
		ps_roll_reverse(stack_a);
	if (x == 'b')
		ps_roll_reverse(stack_b);
	if (x == 'r')
	{
		ps_roll_reverse(stack_b);
		ps_roll_reverse(stack_a);
	}
	if (to_print)
		ft_printf_fd(1, "rr%c\n", x);
}

void	sx(t_stack **stack_a, t_stack **stack_b, char x, int to_print)
{
	if (x == 'a')
		ps_swap(stack_a);
	if (x == 'b')
		ps_swap(stack_b);
	if (x == 's')
	{
		ps_swap(stack_b);
		ps_swap(stack_a);
	}
	if (to_print)
		ft_printf_fd(1, "s%c\n", x);
}
