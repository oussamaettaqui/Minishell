/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:22:20 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/19 12:59:28 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_dollar_char(char *lexer, char q)
{
	int	i;

	i = 0;
	while (lexer && lexer[i])
	{
		if (lexer[i] == q)
			return (1);
		i++;
	}
	return (0);
}

t_token	*check_redirect_out(t_lexer *lexer)
{
	if (lexer->c == '>')
	{
		lexer_advance(lexer);
		return (init_token(ft_strdup(">>"), T_APP, 0));
	}
	return (init_token(ft_strdup(">"), T_R_OUT, 0));
}

t_token	*check_redirect_in(t_lexer *lexer)
{
	if (lexer->c == '<')
	{
		lexer_advance(lexer);
		return (init_token(ft_strdup("<<"), T_HERD, 0));
	}
	return (init_token(ft_strdup("<"), T_R_IN, 0));
}

t_token	*check_char(t_lexer *lexer, t_env **env, t_token *prev_token)
{
	t_helper_st	st;

	init_helper_st(&st);
	while (check_conditions(lexer) == 1)
	{
		st.tmp = check_char_main_helper(lexer, env, prev_token, &st);
		if (!st.tmp)
			return (NULL);
		if (st.tmp == NULL && st.flag == 0)
		{
			ft_free_if_ex(st.value);
			return (init_token(ft_strdup(""), T_ERROR, 0));
		}
		st.value = check_char_helper(&st.flag, st.tmp, st.value);
		if (!st.value)
			return (NULL);
	}
	if (st.flag == 10)
		return (init_token(st.value, T_CHAR, 10));
	if (st.flag == 1)
		return (init_token(st.value, T_DOLLAR, 0));
	return (init_token(st.value, T_CHAR, 1));
}
