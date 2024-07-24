/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:35:51 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/16 16:43:37 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_t_helper(t_helper_st3 *st)
{
	st->fd_in = 0;
	st->fd_out = 0;
	st->flag = 0;
	st->check = 0;
}

int	check_expand_possibility(t_parser *prev, t_parser *parser)
{
	if ((prev && prev->current->type != 5) && ft_strchr(parser->current->value,
			'$') == 1 && parser->current->type != 8)
	{
		return (1);
	}
	return (0);
}

void	start_parsing_helper_0(t_parser *parser, t_helper_st3 *st,
		t_cmds **cmds, t_helper_st4 *s)
{
	if (parser->current->type == 1 || !parser->next)
	{
		st->check = 1;
		append_node_cmds(cmds, s->cmd, &st->fd_in, &st->fd_out);
	}
	s->prev = s->parser;
	s->parser = s->parser->next;
}

void	start_parsing_helper_1(t_args **cmd, t_helper_st3 *st, t_parser *parser)
{
	if (st->flag != 1)
		append_node_cmd(cmd, parser->current->value);
	st->check = 0;
	st->flag = 0;
}

void	start_parsing_helper_2(t_parser *parser, t_helper_st3 *st)
{
	if (parser->current->type == 7)
	{
		st->fd_in = -42;
		st->fd_out = -42;
	}
}
