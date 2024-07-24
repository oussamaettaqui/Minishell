/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:51:09 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/12 17:19:47 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*if_v_not_empty(char *v, char c)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	len = ft_strlen(v);
	if (len == 0)
		return (NULL);
	value = malloc(sizeof(char) * (len + 2));
	if (!value)
		return (NULL);
	i = 0;
	while (v[i])
	{
		value[i] = v[i];
		i++;
	}
	value[i++] = c;
	value[i] = '\0';
	return (value);
}

char	*get_value_of_expand_0(char *tmp, t_env **env, int *flag)
{
	char	*value;

	value = NULL;
	if (ft_strcmp(tmp, "$") == 0)
		return (tmp);
	if (*flag == 1)
		return (tmp);
	if (ft_strchr(tmp, '$') == 1)
		value = expand(tmp, env);
	else
		value = ft_strjoin(value, tmp);
	free(tmp);
	return (value);
}

char	*else_add_char(t_lexer *lexer, char *value)
{
	value = add_char(value, lexer->c);
	lexer_advance(lexer);
	return (value);
}

char	*expand_dollar_0(t_lexer *lexer, t_env **env, int flag, char *tmp)
{
	char	*value;

	value = NULL;
	while (lexer->c != '\0')
	{
		if (lexer->c == '$')
		{
			flag = 1;
			tmp = get_value_of_expand(lexer, env);
		}
		else if (lexer->c == '"')
		{
			lexer_advance(lexer);
			break ;
		}
		else
			value = else_add_char(lexer, value);
		if (flag == 1)
		{
			flag = 0;
			value = ft_strjoin(value, tmp);
			free(tmp);
		}
	}
	return (value);
}
