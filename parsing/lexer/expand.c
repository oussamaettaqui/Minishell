/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:59:05 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 17:37:20 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand(char *tmp, t_env **env)
{
	char	*value;
	t_env	*node;
	char	*t;

	value = NULL;
	t = NULL;
	node = *env;
	tmp = tmp + 1;
	while (node)
	{
		if (ft_strcmp(tmp, node->key) == 0)
		{
			t = ft_strdup(node->value);
			value = ft_strjoin(value, t);
			free(t);
			break ;
		}
		node = node->next;
	}
	if (!value)
		value = ft_strdup("");
	else if (ft_strcmp(tmp, "$") == 0)
		return (tmp);
	return (value);
}

char	*add_char(char *v, char c)
{
	char	*value;

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

char	*get_value_of_expand(t_lexer *lexer, t_env **env)
{
	char	*value;
	char	*tmp;
	int		*flag;
	int		x1;
	t_f		*flags;

	value = NULL;
	tmp = NULL;
	flags = NULL;
	x1 = 0;
	flag = &x1;
	flags = init_flags(flags);
	tmp = get_value_of_expand_1(lexer, tmp, flag, flags);
	value = get_value_of_expand_0(tmp, env, flag);
	free(flags);
	return (value);
}

char	*expand_dollar(t_lexer *lexer, t_env **env)
{
	char	*value;
	char	*tmp;
	int		flag;

	tmp = NULL;
	value = NULL;
	flag = 0;
	value = expand_dollar_0(lexer, env, flag, tmp);
	return (value);
}
