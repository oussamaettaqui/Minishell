/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitching_string_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:15:18 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 17:33:57 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_condition_is_correct(char prev, t_lexer *lexer)
{
	if (prev == '$' && (lexer->c == '=' || lexer->c == ':' || lexer->c == ','
			|| lexer->c == '+' || lexer->c == '%' || lexer->c == '^'
			|| lexer->c == '/' || lexer->c == '&' || lexer->c == '.'))
	{
		return (1);
	}
	return (0);
}

int	check_posibilty_of_expand(t_lexer *lexer, int check, t_token *prev_token)
{
	if (lexer->c != '"' && (check_dollar_(lexer, '$', check) == 1 || check > 0)
		&& prev_token && prev_token->type != 5)
	{
		return (1);
	}
	return (0);
}

char	*minimize_c_convert_ex_status(t_lexer *lexer, t_helper_st *st)
{
	st->flag = 2;
	st->tmp = ft_itoa(g_exit_status);
	lexer_advance(lexer);
	return (st->tmp);
}

char	*minimize_dollar_and_dash(t_lexer *lexer, t_helper_st *st)
{
	st->tmp = ft_strjoin(st->tmp, "himBHs");
	lexer_advance(lexer);
	st->flag = 2;
	return (st->tmp);
}

char	*minimize_same_cases(t_lexer *lexer, t_helper_st *st)
{
	st->tmp = add_char_char(st->tmp, '$');
	st->tmp = add_char_char(st->tmp, lexer->c);
	lexer_advance(lexer);
	st->flag = 2;
	return (st->tmp);
}
