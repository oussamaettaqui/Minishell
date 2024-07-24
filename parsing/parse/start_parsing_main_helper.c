/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing_main_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:13:18 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/16 17:28:52 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_t_helper_4(t_helper_st4 *s, t_parser *parser0)
{
	s->prev = NULL;
	s->parser = parser0;
	s->cmd = NULL;
	s->cmds = NULL;
}

void	start_parsing_main_helper(t_helper_st4 *s, t_helper_st3 *st)
{
	if (st->check == 1)
		s->cmd = NULL;
	start_parsing_helper_2(s->parser, st);
	hand_case_export(s->prev, s->parser, &s->cmd, &st->flag);
}

char	*case_new_line(t_helper_st4 *s)
{
	s->parser->current->value = realloc_value(s->parser->current->value);
	return (s->parser->current->value);
}

char	*case_expand_in_parser(t_helper_st4 *s, t_env **env)
{
	s->parser->current->value = expand_in_parser(s->parser->current->value,
			env);
	return (s->parser->current->value);
}
