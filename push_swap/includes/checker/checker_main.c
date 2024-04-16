/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 07:25:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/03 12:34:28 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		verbose;

	verbose = 0;
	if (ac <= 1)
		return (0);
	if (ac == 2 && ft_strcmp(av[1], "-v") == 0)
		return (0);
	if (ft_strcmp(av[1], "-v") == 0)
		verbose++;
	ps_checker(ac - verbose, &av[verbose], &stack_a, verbose);
	return (0);
}

void	ps_checker(int ac, char **av, t_stack **stack_a, int verbose)
{
	t_stack	*stack_b;
	t_stack	*stack_c;
	int		error;

	*stack_a = 0;
	stack_b = 0;
	stack_c = 0;
	error = ps_parse_entries(ac, av, stack_a);
	if (verbose)
	{
		ft_printf_fd(1, "%sVerbose mode on, HF !%s\n", "\033[0;32m", "\033[0m");
		ps_aff_stacks(stack_a, &stack_b, 'A', 'B');
	}
	if (!error)
		error = ps_process_inputs(stack_a, &stack_b, &stack_c, verbose);
	if (error)
	{
		ps_destroy_stacks(stack_a, &stack_b, &stack_c, &stack_c);
		ps_error_handler(error);
		return ;
	}
	ps_compare_stacks(stack_a, &stack_c);
	ps_destroy_stacks(stack_a, &stack_b, &stack_c, &stack_c);
}

int	ps_process_inputs(t_stack **stack_a, t_stack **stack_b, t_stack **stack_c,
		int verbose)
{
	char	*line;
	int		error;

	*stack_c = ps_sort_stack(*stack_a);
	if (*stack_c == 0)
		return (MALLOC_LIST_ERROR);
	line = get_next_line(0);
	error = 0;
	while (line && error != WRONG_INPUT)
	{
		error = ps_process_line(stack_a, stack_b, line, verbose);
		if (error != WRONG_INPUT)
		{
			free(line);
			line = get_next_line(0);
		}
	}
	if (error && line)
		free(line);
	return (error);
}

void	ps_compare_stacks(t_stack **stack_a, t_stack **stack_c)
{
	if (ps_stack_cmp(stack_a, stack_c) == 0)
		ft_printf_fd(1, "OK\n");
	else
		ft_printf_fd(1, "KO\n");
}

int	ps_process_line(t_stack **stack_a, t_stack **stack_b, char *line,
		int verbose)
{
	if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0)
		px(stack_a, stack_b, line[1], 0);
	else if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0)
		sx(stack_a, stack_b, line[1], 0);
	else if (ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
		|| ft_strcmp(line, "rrr\n") == 0)
		rrx(stack_a, stack_b, line[2], 0);
	else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0
		|| ft_strcmp(line, "rr\n") == 0)
		rx(stack_a, stack_b, line[1], 0);
	else
		return (WRONG_INPUT);
	if (verbose)
		ps_aff_stacks(stack_a, stack_b, 'A', 'B');
	return (0);
}
