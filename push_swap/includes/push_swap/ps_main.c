/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:00:47 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:31:16 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error;

	if (ac <= 1)
		return (0);
	stack_a = 0;
	error = ps_parse_entries(ac, av, &stack_a);
	if (error)
		return (ps_error_handler(error));
	stack_b = 0;
	ps_solve(&stack_a, &stack_b);
	ps_destroy_list(&stack_a, 0);
	ps_destroy_list(&stack_b, 0);
	return (0);
}
