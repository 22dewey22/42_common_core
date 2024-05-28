/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:20:52 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/24 14:27:51 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*parse_cmds(t_split *first_token, t_heredocs **heredocs)
{
	t_split	*current;
	t_split	*tmp;
	t_cmd	*output;
	int		i;

	i = 1;
	output = NULL;
	current = first_token;
	tmp = first_token;
	while (current)
	{
		if (current->tok_type == PIPE)
		{
			if (addback_cmds_list(&output, tmp, i - 1,
					heredocs) == EXIT_FAILURE)
				return (destroy_cmds_list(&output, EXIT_FAILURE), NULL);
			i = 0;
			tmp = current->next;
		}
		i++;
		current = current->next;
	}
	if (addback_cmds_list(&output, tmp, i - 1, heredocs) == EXIT_FAILURE)
		return (destroy_cmds_list(&output, EXIT_FAILURE), NULL);
	return (output);
}

int	addback_cmds_list(t_cmd **start, t_split *first_token, int length,
		t_heredocs **heredocs)
{
	t_cmd	*current;
	t_cmd	*new;

	new = create_new_cmd(first_token, length, heredocs);
	if (!new)
		return (EXIT_FAILURE);
	if (*start == NULL)
	{
		*start = new;
		return (EXIT_SUCCESS);
	}
	current = *start;
	while (current->next)
		current = current->next;
	current->next = new;
	return (EXIT_SUCCESS);
}

int	alloc_output_args(char ***output, t_split *first, int length)
{
	char	**new;
	int		count;

	count = get_arg_count(first, length);
	new = malloc(sizeof(char *) * (count + 1));
	if (new == NULL)
		return (EXIT_FAILURE);
	ft_bzero(new, sizeof(char *) * (count + 1));
	*output = new;
	return (EXIT_SUCCESS);
}

int	set_cmd_arg(t_cmd *output, t_split *first, int length,
		t_heredocs **heredocs)
{
	int		index;
	t_split	*current;

	current = first;
	index = 0;
	if (alloc_output_args(&output->args, first, length - 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (current && --length)
	{
		if (current->tok_type != CMD)
		{
			if (add_file_list(&output->files, current, heredocs,
					&length) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			current = current->next;
		}
		else
		{
			output->args[index] = ft_strdup(current->str);
			if (output->args[index++] == NULL)
				return (EXIT_FAILURE);
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

int	add_file_list(t_file **files, t_split *current, t_heredocs **heredocs,
		int *length)
{
	t_file	*output;
	char	*file_name;

	output = malloc(sizeof(t_file));
	if (output == NULL)
		return (EXIT_FAILURE);
	ft_bzero(output, sizeof(t_file));
	output->fd = -1;
	file_name = ft_strdup(current->next->str);
	if (file_name == NULL)
		return (free(output), EXIT_FAILURE);
	init_file_output(output, file_name, current->tok_type, heredocs);
	addback_file_list(files, output);
	*length -= 1;
	return (EXIT_SUCCESS);
}
