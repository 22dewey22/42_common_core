/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_walid2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:45:16 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/28 13:43:08 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	line_is_walid_redir(t_split **first, int *open_par, t_mini *mini)
{
	t_split	*current;
	char	*next;
	int		value;

	next = NULL;
	current = *first;
	if (current->next)
		next = current->next->str;
	if (!(current->next && current->next->tok_type == CMD) || !current->next)
		return (syntax_err_msg(get_syntax_err_value(current), current->str,
				next));
	else if (current->tok_type == HD)
	{
		value = get_hd_file(current->next->str, mini);
		if (value)
			return (value);
		return (line_is_walid(&current->next->next, open_par, mini));
	}
	else
		return (line_is_walid(&current->next->next, open_par, mini));
}

int	line_is_walid_cmd_end(t_split **first, int *open_par, t_mini *mini)
{
	t_split	*current;
	char	*next;

	next = NULL;
	current = *first;
	if (current->next)
		next = current->next->str;
	if (!current->next || !(current->next->tok_type == CMD
			|| current->next->tok_type == PAR_OPEN
			|| current->next->sub_tok_type == REDIR))
		return (syntax_err_msg(get_syntax_err_value(current), current->str,
				next));
	return (line_is_walid(&current->next, open_par, mini));
}

int	line_is_walid_par_open(t_split **first, int *open_par, t_mini *mini)
{
	t_split	*current;
	char	*next;

	next = NULL;
	current = *first;
	if (current->next)
		next = current->next->str;
	*open_par += 1;
	if (!(current->next) || !((current->next->tok_type == PAR_OPEN)
			|| current->next->sub_tok_type == REDIR
			|| current->next->tok_type == CMD))
		return (syntax_err_msg(SYNTAX_ERR_PAR_OPEN, current->str, next));
	return (line_is_walid(&current->next, open_par, mini));
}

int	line_is_walid_par_close(t_split **first, int *open_par, t_mini *mini)
{
	t_split	*current;
	char	*next;

	current = *first;
	next = NULL;
	if (current->next)
		next = current->next->str;
	if (*open_par <= 0)
		return (syntax_err_msg(SYNTAX_ERR_PAR_CLOSE, current->str, NULL));
	if (current->next && (current->next->tok_type == CMD
			|| current->next->tok_type == PAR_OPEN
			|| current->next->tok_type == PIPE
			|| current->next->sub_tok_type == REDIR))
		return (syntax_err_msg(SYNTAX_ERR_PAR_CLOSE, current->str, next));
	*open_par -= 1;
	return (line_is_walid(&current->next, open_par, mini));
}

int	line_is_walid_cmd(t_split **first, int *open_par, t_mini *mini)
{
	t_split	*current;

	current = *first;
	if (current->next && current->next->tok_type == PAR_OPEN)
		return (syntax_err_msg(SYNTAX_ERR_PAR_OPEN, current->str,
				current->next->str));
	return (line_is_walid(&current->next, open_par, mini));
}
