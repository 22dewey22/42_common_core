/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:19:07 by david             #+#    #+#             */
/*   Updated: 2023/12/02 22:31:03 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_val_is_min(t_stack **first, int value)
{
	t_stack	*current;

	if (*first == 0)
		return (1);
	current = *first;
	while (current->next != *first)
	{
		if (current->value < value)
			return (0);
		current = current->next;
	}
	if (current->value >= value)
		return (1);
	return (0);
}

int	ps_val_is_max(t_stack **first, int value)
{
	t_stack	*current;

	if (*first == 0)
		return (1);
	current = *first;
	while (current->next != *first)
	{
		if (current->value > value)
			return (0);
		current = current->next;
	}
	if (current->value <= value)
		return (1);
	return (0);
}

t_stack	*ps_sort_stack(t_stack *stack_top)
{
	t_stack	*sorted;
	t_stack	*current;
	t_tree	*tree_top;

	tree_top = malloc(sizeof(*tree_top));
	if (!tree_top)
		return (0);
	tree_top->value = stack_top->value;
	tree_top->left = 0;
	tree_top->right = 0;
	current = stack_top->next;
	sorted = 0;
	while (current != stack_top)
	{
		if (ps_add_to_tree(tree_top, current->value) == -1)
			return (ps_tree_burner(tree_top));
		current = current->next;
	}
	if (ps_decomp_tree(tree_top, &sorted) == -1)
		ps_destroy_list(&sorted, MALLOC_LIST_ERROR);
	ps_tree_burner(tree_top);
	return (sorted);
}

void	ps_destroy_stacks(t_stack **stack_a, t_stack **stack_b,
		t_stack **stack_c, t_stack **stack_d)
{
	ps_destroy_list(stack_a, NO_ERROR);
	ps_destroy_list(stack_b, NO_ERROR);
	ps_destroy_list(stack_c, NO_ERROR);
	ps_destroy_list(stack_d, NO_ERROR);
}
