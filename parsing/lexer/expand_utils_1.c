/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:20:45 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:32 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*if_get_tmp_value(char *tmp, t_lexer *lexer, t_f *flags)
{
	if (ft_strcmp(tmp, "$") == 0 && flags->s == 0)
	{
		free(tmp);
		tmp = NULL;
		lexer_advance(lexer);
		if (lexer->c == '\0' || lexer->c == '"')
			tmp = ft_strdup("");
		flags->s = 1;
		return (tmp);
	}
	flags->s = 1;
	return (NULL);
}

int	check_condition(t_lexer *lexer)
{
	if (lexer->c == '\'' || lexer->c == '"' || lexer->c == ' '
		|| ft_isalpha(lexer->c) == 0)
	{
		return (1);
	}
	return (0);
}

char	*condition_case_status(char *tmp, t_lexer *lexer)
{
	free(tmp);
	tmp = ft_itoa(g_exit_status);
	lexer_advance(lexer);
	return (tmp);
}

char	*condition_of_status(char *tmp, int *flag, t_lexer *lexer)
{
	*flag = 1;
	tmp = condition_case_status(tmp, lexer);
	return (tmp);
}

char	*get_value_of_expand_1(t_lexer *lexer, char *tmp, int *flag, t_f *flags)
{
	while (lexer->c != '\0')
	{
		if (lexer->c == '?')
		{
			tmp = condition_of_status(tmp, flag, lexer);
			break ;
		}
		else if (lexer->c >= 48 && lexer->c <= 57)
			tmp = if_get_tmp_value(tmp, lexer, flags);
		if (lexer->c == '$' && flags->f == 0)
		{
			tmp = add_char(tmp, lexer->c);
			flags->f = 1;
		}
		else if (check_condition(lexer) == 1)
			break ;
		else
			tmp = add_char(tmp, lexer->c);
		if (!tmp)
			return (free(tmp), NULL);
		lexer_advance(lexer);
	}
	return (tmp);
}
