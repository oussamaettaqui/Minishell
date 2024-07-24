/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:38:44 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/19 13:03:11 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*single_quotes_case(char *tmp, int *flag, t_token *prev_token,
		char *value)
{
	if (check_dollar_char(tmp, '$') == 1)
		*flag = 1;
	if (!tmp && prev_token && prev_token->type == 7)
	{
		if (value)
			free(value);
		return (NULL);
	}
	else if (!tmp && !prev_token)
	{
		if (value)
			free(value);
		return (NULL);
	}
	return (tmp);
}

char	*double_quotes_case(char *tmp, t_token *prev_token, char *value)
{
	if (!tmp && prev_token && prev_token->type == 7)
	{
		if (value)
			free(value);
		return (NULL);
	}
	else if (!tmp && !prev_token)
	{
		if (value)
			free(value);
		return (NULL);
	}
	return (tmp);
}

char	*dollar_case(t_lexer *lexer, int *flag, t_env **env,
		t_token *prev_token)
{
	char	*tmp;

	tmp = dollar(lexer, env, prev_token);
	if (ft_strchr(tmp, ' ') == 1)
		*flag = 10;
	if (tmp && tmp[0] == '\0')
		*flag = 1;
	else if (tmp && ft_strchr(tmp, '$') == 1)
		*flag = 1;
	return (tmp);
}

char	*check_char_helper(int *flag, char *tmp, char *value)
{
	if (*flag == 4)
		tmp = ft_strdup("");
	if (*flag == 2)
	{
		value = ft_strjoin(value, "$");
		*flag = 0;
	}
	value = ft_strjoin(value, tmp);
	free(tmp);
	tmp = NULL;
	return (value);
}

int	check_conditions(t_lexer *lexer)
{
	if (lexer->c != '>' && lexer->c != '<' && lexer->c != '|' && lexer->c != ' '
		&& lexer->c != '\t' && lexer->c != '\0')
	{
		return (1);
	}
	return (0);
}
