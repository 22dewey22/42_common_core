/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:20:14 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/23 14:56:22 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quote_validity(char *str, int *exit_status)
{
	char	isquote;

	isquote = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			if (isquote == 0)
				isquote = *str;
			else if (isquote == *str)
				isquote = 0;
		}
		str++;
	}
	if (isquote)
	{
		*exit_status = 2;
		return (ft_printf_fd(2, "jean-mishell: unexpected newline while"),
			ft_printf_fd(2, " looking for matching `%c'\n", isquote),
			SYNTAX_ERR_QUOTE);
	}
	return (EXIT_SUCCESS);
}

int	has_quote(char *str)
{
	while (*str)
	{
		if (*str == '\'' || *str == '"')
			return (1);
		str++;
	}
	return (0);
}

void	quote_trimmer(char *str)
{
	char	isquote;
	int		j;
	int		i;

	i = 0;
	isquote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && (isquote == 0
				|| isquote == str[i]))
		{
			j = 0;
			if (isquote == 0)
				isquote = str[i];
			else
				isquote = 0;
			while (str[i + ++j - 1])
				str[i + j - 1] = str[i + j];
		}
		else
			i++;
	}
}
