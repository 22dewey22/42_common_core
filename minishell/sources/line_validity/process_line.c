/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/28 13:31:07 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_global_validity(t_mini *mini, t_split **parsed_line,
		int validity)
{
	int	parenthesis;

	parenthesis = 0;
	validity = line_is_walid(parsed_line, &parenthesis, mini);
	if (validity && validity != EXIT_FAILURE && validity != E_STATUS_SIGINT)
	{
		mini->exit_status = SYNTAX_ERR;
		remove_hd_list(&mini->heredocs);
		return (destroy_split_list(parsed_line, EXIT_SUCCESS));
	}
	else if (validity == EXIT_FAILURE)
	{
		remove_hd_list(&mini->heredocs);
		return (destroy_split_list(parsed_line, EXIT_FAILURE));
	}
	else if (validity == E_STATUS_SIGINT)
		return (remove_hd_list(&mini->heredocs), destroy_split_list(parsed_line,
				EXIT_SUCCESS));
	return (EXIT_SUCCESS);
}

int	process_line(char *line, t_mini *mini)
{
	t_split	*parsed_line;
	int		validity;

	validity = 0;
	parsed_line = NULL;
	if (quote_validity(line, &mini->exit_status))
		return (EXIT_SUCCESS);
	if (line_parser(line, &parsed_line) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	add_token_types(&parsed_line);
	if (check_first_token(parsed_line, &mini->exit_status) != EXIT_SUCCESS)
		return (destroy_split_list(&parsed_line, EXIT_SUCCESS));
	if (check_global_validity(mini, &parsed_line, validity) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (!parsed_line)
		return (EXIT_SUCCESS);
	if (create_tree(&mini->ast, &parsed_line) == EXIT_FAILURE)
		return (remove_hd_list(&mini->heredocs), EXIT_FAILURE);
	if (select_node(mini->ast, mini) == EXIT_FAILURE)
		return (remove_hd_list(&mini->heredocs), destroy_tree(&mini->ast,
				EXIT_FAILURE));
	return (remove_hd_list(&mini->heredocs), destroy_tree(&mini->ast,
			EXIT_SUCCESS));
}
