/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:19:07 by david             #+#    #+#             */
/*   Updated: 2023/12/03 08:42:02 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_destroy_list(t_stack **first, int error)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *first;
	if (!current)
		return (error);
	while (current->next != *first)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	*first = 0;
	return (error);
}

int	ps_addback(t_stack **first, int value)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(*new));
	if (!new)
		return (-1);
	if (*first == 0)
		*first = new;
	else
	{
		current = *first;
		while (current->next != *first)
			current = current->next;
		current->next = new;
	}
	new->value = value;
	new->next = *first;
	return (0);
}

int	ps_addfront(t_stack **first, int value)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(*new));
	if (!new)
		return (-1);
	if (*first == 0)
		*first = new;
	else
	{
		current = *first;
		while (current->next != *first)
			current = current->next;
		current->next = new;
	}
	new->value = value;
	new->next = *first;
	*first = new;
	return (0);
}

int	ps_get_stack_len(t_stack **first)
{
	t_stack	*current;
	int		i;

	if (*first == 0)
		return (0);
	i = 1;
	current = *first;
	while (current->next != *first)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	ps_stack_cmp(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	if (*stack_a == 0 && *stack_b == 0)
		return (0);
	else if (*stack_a == 0 || *stack_b == 0)
		return (1);
	curr_a = *stack_a;
	curr_b = *stack_b;
	while (curr_a->value == curr_b->value && curr_a->next != *stack_a)
	{
		curr_a = curr_a->next;
		curr_b = curr_b->next;
	}
	return (curr_a->value - curr_b->value);
}
