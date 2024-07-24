/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:59:49 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/13 18:54:26 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_char(t_lexer *lexer)
{
	char	*tmp;
	char	*sub;
	int		begin;
	int		end;

	begin = lexer->i;
	while (lexer->c != '<' && lexer->c != '>' && lexer->c != '|'
		&& lexer->c != '\t' && lexer->c != ' ' && lexer->c != '"'
		&& lexer->c != '\0' && lexer->c != '\'' && lexer->c != '$')
	{
		lexer_advance(lexer);
	}
	end = lexer->i;
	sub = ft_substr(lexer->src, begin, end - begin);
	tmp = sub;
	if (tmp == NULL)
		printf("ERROR\n");
	return (tmp);
}
