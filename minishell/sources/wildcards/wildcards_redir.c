/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:25:24 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/23 10:31:29 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	process_wildcard_match(char **str_with_w, char *w_match)
{
	char	*tmp;

	tmp = *str_with_w;
	if (w_match)
	{
		*str_with_w = ft_strdup(w_match);
		if (*str_with_w == NULL)
		{
			*str_with_w = tmp;
			return (EXIT_FAILURE);
		}
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int	expand_one_wildcard_redir(char **str_with_w, char **files)
{
	int		i;
	char	*w_match;

	i = -1;
	w_match = NULL;
	while (files[++i])
	{
		if (wildcard_match(*str_with_w, files[i]))
		{
			if (w_match == NULL)
				w_match = files[i];
			else
				return (SYNTAX_ERR_REDIR);
		}
	}
	return (process_wildcard_match(str_with_w, w_match));
}

int	check_redir_ambiguity(t_split *wildcard, t_split **tok_with_w)
{
	t_split	*tmp;

	if (!wildcard)
		return (EXIT_SUCCESS);
	if (!wildcard->next)
	{
		wildcard->next = (*tok_with_w)->next;
		tmp = *tok_with_w;
		*tok_with_w = wildcard;
		destroy_split(tmp);
		return (EXIT_SUCCESS);
	}
	else
		return (destroy_split_list(&wildcard, EXIT_FAILURE),
			syntax_err_msg(SYNTAX_ERR_REDIR, (*tok_with_w)->str, NULL));
}

int	expand_token_list(t_split **first, char **file_list)
{
	t_split	*current;
	t_split	*tmp;

	current = *first;
	if (!file_list)
		return (EXIT_SUCCESS);
	while (current)
	{
		if (current && current->sub_tok_type == REDIR)
			current = current->next->next;
		else if (has_wildcard(current->str))
		{
			tmp = current->next;
			if (expand_one_wildcard(&current, file_list) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			current = tmp;
		}
		else
			current = current->next;
	}
	return (EXIT_SUCCESS);
}
