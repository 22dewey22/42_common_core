/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:03:13 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:21:02 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_parse_entries(int ac, char **av, t_stack **stack_a)
{
	int	error;

	if (ac > 2)
		return (ps_parse_mult_args(ac, av, stack_a));
	else if (ac == 2)
	{
		error = ps_parse_one_arg(stack_a, av[1]);
		if (error)
			return (ps_destroy_list(stack_a, error));
	}
	else
		return (NO_INPUT);
	return (NO_ERROR);
}

int	ps_parse_mult_args(int ac, char **av, t_stack **stack_a)
{
	int	i;

	i = 1;
	if (ps_valid_list(ac, av, 1) == 0)
	{
		while (i < ac)
		{
			if (ps_addback(stack_a, ft_atoi(av[i++])) == MALLOC_LIST_ERROR)
				return (ps_destroy_list(stack_a, MALLOC_LIST_ERROR));
		}
		return (NO_ERROR);
	}
	else
		return (INVALID_LIST);
}

int	ps_parse_one_arg(t_stack **stack_a, char *av)
{
	int		i;
	char	**split;

	split = ft_split(av, ' ');
	if (!split)
		return (MALLOC_LIST_ERROR);
	i = 0;
	if (ft_get_split_len(split) == 0)
		return (ft_free_split(split, INVALID_LIST));
	if (ps_valid_list(ft_get_split_len(split), split, 0) == -1)
		return (ft_free_split(split, INVALID_LIST));
	while (split[i])
	{
		if (ps_addback(stack_a, ft_atoi(split[i++])) == -1)
			return (ft_free_split(split, MALLOC_LIST_ERROR));
	}
	return (ft_free_split(split, NO_ERROR));
}

int	ps_valid_stack(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack_a;
	if (current->isvalid == 0)
		return (INVALID_LIST);
	while (current->next != *stack_a)
	{
		if (current->isvalid == 0)
			return (INVALID_LIST);
		tmp = current->next;
		while (tmp != *stack_a)
		{
			if (tmp->value == current->value)
				return (INVALID_LIST);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (VALID_LIST);
}

int	ps_valid_list(int ac, char **av, int isnt_split)
{
	int		i;
	int		j;
	long	buf;

	if (ps_check_len_digits(ac, av, isnt_split) == -1)
		return (-1);
	i = isnt_split;
	while (i < ac)
	{
		buf = ft_atol(av[i]);
		if (buf > INT_MAX || buf < INT_MIN)
			return (-1);
		if (i < ac - 1)
		{
			j = i + 1;
			while (j < ac)
			{
				if (buf == ft_atol(av[j]))
					return (-1);
				j++;
			}
		}
		i++;
	}
	return (0);
}
