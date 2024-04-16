/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:18:10 by david             #+#    #+#             */
/*   Updated: 2023/12/02 22:31:44 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_add_to_tree(t_tree *tree_top, int value)
{
	t_tree	*current;
	t_tree	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (-1);
	new->value = value;
	new->left = 0;
	new->right = 0;
	current = tree_top;
	while ((current->left && value < current->value) || (current->right
			&& value > current->value))
	{
		if (value < current->value)
			current = current->left;
		else
			current = current->right;
	}
	if (value > current->value)
		current->right = new;
	else
		current->left = new;
	return (0);
}

int	ps_decomp_tree(t_tree *tree_top, t_stack **sorted_list)
{
	int	output;

	output = 0;
	if (tree_top->left)
		output = ps_decomp_tree(tree_top->left, sorted_list);
	if (!output && tree_top)
		output = ps_addback(sorted_list, tree_top->value);
	else
		return (-1);
	if (tree_top->right && !output)
		return (ps_decomp_tree(tree_top->right, sorted_list));
	return (output);
}

t_stack	*ps_tree_burner(t_tree *tree_top)
{
	t_tree	*left;
	t_tree	*right;

	if (!tree_top)
		return (0);
	left = tree_top->left;
	right = tree_top->right;
	free(tree_top);
	ps_tree_burner(left);
	return (ps_tree_burner(right));
}
