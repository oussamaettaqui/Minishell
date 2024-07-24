/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:40:19 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 18:40:42 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser	*initialize_parser(char *line, t_env **env)
{
	t_parser	*parser;
	t_lexer		*lexer;

	parser = NULL;
	lexer = init_lexer(line);
	init_parser(&parser, lexer, env);
	if (check_parser(&parser, env) != 0)
	{
		ft_lstclear_parser(&parser);
		return (NULL);
	}
	return (parser);
}
