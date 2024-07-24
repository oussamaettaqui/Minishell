/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetching_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:39:22 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 17:34:32 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_quotes(t_lexer *lexer, char q)
{
	int		begin;
	int		i;
	char	advance;

	advance = lexer->c;
	i = 1;
	if (advance == q)
		lexer_advance(lexer);
	else
	{
		lexer_advance(lexer);
		lexer_advance(lexer);
	}
	begin = lexer->i;
	if (advance == q && lexer->src[begin] == '\0')
		return (0);
	while (lexer->src[begin])
	{
		if (lexer->src[begin] == q)
			return (i);
		else if (lexer->src[begin++] != advance)
			i++;
	}
	return (0);
}

int	check_dollar_(t_lexer *lexer, char q, int i)
{
	int	begin;

	begin = lexer->i;
	while (lexer->src[begin] && begin <= i)
	{
		if (lexer->src[begin] == q)
			return (1);
		begin++;
	}
	return (0);
}

char	*single_quotes(t_lexer *lexer, t_token *prev_token)
{
	char			*tmp;
	unsigned int	start;
	unsigned int	end;
	char			*sub;
	int				check;

	tmp = NULL;
	check = check_quotes(lexer, '\'');
	if (check == 0)
		return (print_error_quotes(1, prev_token), NULL);
	else if (check > 0)
	{
		start = lexer->i;
		while (lexer->c != '\'' && lexer->c != '\0')
			lexer_advance(lexer);
		end = lexer->i;
		sub = ft_substr(lexer->src, start, end - start);
		tmp = sub;
		if (tmp == NULL)
			return (NULL);
		lexer_advance(lexer);
	}
	return (tmp);
}

char	*double_quotes(t_lexer *lexer, t_env **env, t_token *prev_token)
{
	char			*tmp;
	unsigned int	start;
	unsigned int	end;
	char			*sub;
	int				check;

	tmp = NULL;
	check = check_quotes(lexer, '"');
	if (check == 0)
		return (print_error_quotes(2, prev_token), NULL);
	if (check_posibilty_of_expand(lexer, check, prev_token) == 1)
		tmp = expand_dollar(lexer, env);
	else if (check > 0)
	{
		start = lexer->i;
		while (lexer->c != '"' && lexer->c != '\0')
			lexer_advance(lexer);
		end = lexer->i;
		sub = ft_substr(lexer->src, start, end - start);
		tmp = sub;
		if (tmp == NULL)
			return (NULL);
		lexer_advance(lexer);
	}
	return (tmp);
}

char	*dollar(t_lexer *lexer, t_env **env, t_token *prev_token)
{
	int			i;
	char		prev;
	char		*v;
	t_helper_st	st;
	char		*return_v;

	init_helper_st(&st);
	i = 0;
	v = NULL;
	return_v = NULL;
	prev = lexer->c;
	st.tmp = minize_first_conditions(lexer, env, &st, prev_token);
	v = minimize_dollar_function(&st, prev_token, env, i);
	if ((st.flag) == 3 || ((st.flag) == 0 && v))
		return (v);
	return (st.value);
}
