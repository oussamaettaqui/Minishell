/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:08:40 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/19 12:51:35 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

unsigned int	get_len_of_it(t_lexer *lexer, char c)
{
	unsigned int	end;

	end = lexer->src_len - 1;
	while (lexer->src[end] != c)
		end--;
	if (lexer->src[end] == c)
		return (end);
	else
		return (0);
}

char	*handl_double_quotes(char *tmp, t_token *prev_token, char *value,
		int *flag)
{
	tmp = double_quotes_case(tmp, prev_token, value);
	if (!tmp)
		return (NULL);
	else if (ft_strcmp(tmp, "$") == 0)
		*flag = 1;
	return (tmp);
}

void	init_helper_st(t_helper_st *st)
{
	st->value = NULL;
	st->tmp = NULL;
	st->flag = 0;
}

char	*check_char_main_helper(t_lexer *lexer, t_env **env,
		t_token *prev_token, t_helper_st *st)
{
	if (lexer->c == '\'')
	{
		st->tmp = single_quotes(lexer, prev_token);
		st->tmp = single_quotes_case(st->tmp, &st->flag, prev_token, st->value);
		if (!st->tmp)
			return (NULL);
	}
	else if (lexer->c == '"')
	{
		st->tmp = double_quotes(lexer, env, prev_token);
		st->tmp = handl_double_quotes(st->tmp, prev_token, st->value,
				&st->flag);
		if (!st->tmp)
			return (NULL);
	}
	else if (lexer->c == '$')
		st->tmp = dollar_case(lexer, &st->flag, env, prev_token);
	else
		st->tmp = get_char(lexer);
	return (st->tmp);
}
