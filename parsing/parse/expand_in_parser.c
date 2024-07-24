/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 02:03:47 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 14:09:11 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_strncmp_exp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*add_char_char(char *v, char c)
{
	char	*value;
	int		i;
	int		len;

	i = 0;
	len = 0;
	value = NULL;
	if (!v)
	{
		value = malloc(sizeof(char) * 2);
		if (!value)
			return (NULL);
		value[0] = c;
		value[1] = '\0';
	}
	else
		value = if_v_not_empty(v, c);
	if (v)
		free(v);
	return (value);
}

static char	*get_char_key(int i, char *key, char *s, t_helper_st2 *st)
{
	if (s[i] && s[i + 1] && s[i + 1] == '?')
	{
		key = add_char_char(key, s[i++]);
		key = add_char_char(key, s[i++]);
	}
	else
	{
		if (s[i] == '$')
			key = add_char_char(key, s[i]);
		i++;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\''
			&& s[i] != '"' && s[i] != '?')
		{
			if (s[i + 1] && ft_isalpha(s[i + 1]) == 0)
			{
				key = add_char_char(key, s[i]);
				break ;
			}
			key = add_char_char(key, s[i]);
			i++;
		}
	}
	st->i = i;
	return (key);
}

static char	*minimize_if_key_not_empty(t_helper_st2 *st, t_env **env)
{
	if (st->key[1] == ' ' || st->key[1] == '>' || st->key[1] == '<')
	{
		st->src = ft_strjoin(st->src, st->key);
	}
	else
	{
		st->v = expand(st->key, env);
		st->src = ft_strjoin(st->src, st->v);
	}
	free(st->v);
	free(st->key);
	st->key = NULL;
	return (st->src);
}

char	*expand_in_parser(char *s, t_env **env)
{
	t_helper_st2	st;

	init_helper_st2(&st);
	while (s[st.i])
	{
		if (s[st.i] == '$')
		{
			st.key = get_char_key(st.i, st.key, s, &st);
			if (ft_strncmp_exp(st.key, "$?", 2) == 0)
				st.src = expand_exit_status(st.src, st.key);
			else if (ft_strcmp(st.key, "$") == 0)
				st.src = expnad_dollar_only(st.src, st.key, s, st.i);
			else if (st.key)
				st.src = minimize_if_key_not_empty(&st, env);
			if (!s[st.i])
				break ;
		}
		else if (s[st.i] != '$')
		{
			st.src = add_char_char(st.src, s[st.i]);
		}
		st.i ++;
	}
	free_tow_char(s, st.key);
	return (st.src);
}
