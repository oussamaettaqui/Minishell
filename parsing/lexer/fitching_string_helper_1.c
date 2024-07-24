/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitching_string_helper_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:07:26 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 17:34:50 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*minimize_else(t_lexer *lexer, t_helper_st *st)
{
	st->tmp = get_char(lexer);
	if (lexer->c == ' ' && st->tmp[0] == '\0')
		st->flag = 1;
	return (st->tmp);
}

char	*minimize_case_d_s_quotes(t_lexer *lexer, t_helper_st *st, t_env **env,
		t_token *prev_token)
{
	st->flag = 2;
	if (lexer->c == '\'')
		return (ft_strdup(""));
	else if (lexer->c == '"')
	{
		st->tmp = double_quotes(lexer, env, prev_token);
		if (prev_token && !st->tmp && prev_token->type == 7)
			return (NULL);
		else if (!st->tmp && !prev_token)
			return (NULL);
		if (!st->tmp || st->tmp[0] == '\0')
			st->flag = 0;
	}
	return (st->tmp);
}

char	*minize_first_conditions(t_lexer *lexer, t_env **env, t_helper_st *st,
		t_token *prev_token)
{
	char	prev;

	prev = lexer->c;
	lexer_advance(lexer);
	if (lexer->c == '\0')
		st->flag = 1;
	else if (lexer->c == '?')
		st->tmp = minimize_c_convert_ex_status(lexer, st);
	else if (prev == '$' && lexer->c == '-')
		st->tmp = minimize_dollar_and_dash(lexer, st);
	else if (check_condition_is_correct(prev, lexer) == 1)
		st->tmp = minimize_same_cases(lexer, st);
	else if (lexer->c >= 48 && lexer->c <= 57)
		lexer_advance(lexer);
	else if (lexer->c == '\'' || lexer->c == '"')
	{
		st->tmp = minimize_case_d_s_quotes(lexer, st, env, prev_token);
		if (!st->tmp)
			return (NULL);
		else if (ft_strcmp(st->tmp, "") == 0)
			return (st->tmp);
	}
	else
		st->tmp = minimize_else(lexer, st);
	return (st->tmp);
}

char	*check_flags_and_join(t_helper_st *st)
{
	if (st->flag == 2)
		st->value = ft_strjoin(st->value, st->tmp);
	else
	{
		st->value = ft_strjoin(st->value, "$");
		if (st->tmp)
			st->value = ft_strjoin(st->value, st->tmp);
	}
	free(st->tmp);
	return (st->value);
}

char	*if_no_prev_befor_token(t_helper_st *st, int i, char *v, t_env **env)
{
	st->value = ft_strjoin(st->value, "$");
	while (st->tmp && st->tmp[i])
	{
		if (ft_isalpha(st->tmp[i]) != 1)
			break ;
		st->value = add_char_char(st->value, st->tmp[i]);
		i++;
	}
	if (!st->value)
		return (NULL);
	v = expand(st->value, env);
	if (&st->tmp[i])
		v = ft_strjoin(v, &st->tmp[i]);
	free(st->value);
	st->flag = 3;
	free(st->tmp);
	return (v);
}
