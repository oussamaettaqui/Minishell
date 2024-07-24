/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:12:21 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/11 18:35:59 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_lexer	*init_lexer(char *value)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->src = value;
	lexer->i = 0;
	lexer->c = value[lexer->i];
	lexer->src_len = ft_strlen(value);
	lexer->ex_s = 0;
	return (lexer);
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->src_len && lexer->c != '\0')
	{
		lexer->i += 1;
		lexer->c = lexer->src[lexer->i];
	}
}

void	lexer_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
		lexer_advance(lexer);
}

t_token	*get_next_token(t_lexer *lexer, t_env **env, t_token *token)
{
	while (lexer->c != '\0')
	{
		if (lexer->c == ' ' || lexer->c == '\t')
			lexer_skip_whitespace(lexer);
		else if (lexer->c == '|')
		{
			lexer_advance(lexer);
			return (init_token(ft_strdup("|"), T_PIPE, 0));
		}
		else if (lexer->c == '>')
		{
			lexer_advance(lexer);
			return (check_redirect_out(lexer));
		}
		else if (lexer->c == '<')
		{
			lexer_advance(lexer);
			return (check_redirect_in(lexer));
		}
		else if (lexer->c != ' ' || lexer->c != '\t')
			return (check_char(lexer, env, token));
	}
	return (init_token(ft_strdup("EOF"), T_EOF, 0));
}
