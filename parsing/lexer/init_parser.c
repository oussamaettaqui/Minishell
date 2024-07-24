/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:04:23 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/11 18:38:04 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_parser(t_parser **parser, t_lexer *lexer, t_env **env)
{
	t_token	*token;

	token = NULL;
	token = get_next_token(lexer, env, token);
	while (token && token->type != 6)
	{
		append_node_parser(parser, token);
		token = get_next_token(lexer, env, token);
	}
	if (token)
	{
		free(token->value);
		free(token);
	}
	free(lexer);
}
