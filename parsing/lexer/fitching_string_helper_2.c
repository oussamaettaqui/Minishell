/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitching_string_helper_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:39:00 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 17:29:20 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*if_prev_exist_befor_token(t_helper_st *st, int i, char *v, t_env **env)
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

char	*join_tow_time_and_free(t_helper_st *st)
{
	st->value = ft_strjoin(st->value, "$");
	st->value = ft_strjoin(st->value, st->tmp);
	free(st->tmp);
	return (st->value);
}

char	*minimize_else_dollar(t_helper_st *st, t_token *prev_token, int i,
		t_env **env)
{
	char	*v;

	v = NULL;
	if (st->flag == 0 && prev_token && prev_token->type != 5)
	{
		v = if_prev_exist_befor_token(st, i, v, env);
		if (!v)
			return (NULL);
		return (v);
	}
	else
	{
		st->value = join_tow_time_and_free(st);
		return (st->value);
	}
}

char	*minimize_dollar_function(t_helper_st *st, t_token *prev_token,
		t_env **env, int i)
{
	char	*v;

	v = NULL;
	if (st->flag == 1 || st->flag == 2)
	{
		st->value = check_flags_and_join(st);
		if (!st->value)
			return (NULL);
		st->flag = 1;
	}
	else if (!prev_token)
	{
		if (st->flag == 0)
			v = if_no_prev_befor_token(st, i, v, env);
	}
	else
		v = minimize_else_dollar(st, prev_token, i, env);
	if (!v)
		return (NULL);
	if (st->flag == 3 || (st->flag == 0 && v))
		return (v);
	return (st->value);
}
