/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:02:51 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/23 14:52:47 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_err_msg(int err_value, char *current_token, char *token)
{
	if (token == NULL)
	{
		token = "newline";
	}
	if (err_value == SYNTAX_ERR_REDIR)
		err_printf("jean-mishell: %s: ambiguous redirect\n", current_token,
			NULL, NULL);
	else
		err_printf("jean-mishell: syntax error near unexpected token `%s'\n",
			token, NULL, NULL);
	return (err_value);
}
