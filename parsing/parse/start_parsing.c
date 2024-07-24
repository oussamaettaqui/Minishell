/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:49:37 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/19 16:18:34 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_count_here_doc(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser)
	{
		if (parser->current->type == 5)
			i++;
		if (i == 17)
			return (-1);
		parser = parser->next;
	}
	return (0);
}

static int	check_count_here_doc(t_parser *parser, int *fd_in, int *fd_out)
{
	t_parser	*parser_count_here;

	parser_count_here = parser;
	init_fds(fd_in, fd_out);
	if (ft_count_here_doc(parser_count_here) == -1)
		return (-1);
	return (0);
}

int	check_condition_export(t_parser *prev, t_parser *parser)
{
	if ((!prev && ft_strcmp(parser->current->value, "export") != 0) || (prev
			&& ft_strcmp(prev->current->value, "export") != 0))
	{
		return (1);
	}
	return (0);
}

void	hand_case_export(t_parser *prev, t_parser *parser, t_args **cmd,
		int *flag)
{
	char	**split_parser;
	int		i;

	split_parser = NULL;
	i = 0;
	if (check_condition_export(prev, parser) == 1)
	{
		if (parser->current->is_expand == 10)
		{
			split_parser = ft_split(parser->current->value, ' ');
			while (split_parser[i])
			{
				append_node_cmd(cmd, split_parser[i]);
				i++;
			}
			free_double_pointer(split_parser);
			prev = parser;
			if (parser->next)
				parser = parser->next;
			*flag = 1;
		}
	}
}

t_cmds	*start_parsing(t_parser *parser0, t_env **env)
{
	t_helper_st3	st;
	t_helper_st4	s;

	init_t_helper(&st);
	init_t_helper_4(&s, parser0);
	if (check_count_here_doc(parser0, &st.fd_in, &st.fd_out) == -1)
		return (NULL);
	while (s.parser && s.parser->current->type != 6)
	{
		if (!s.parser->next)
		{
			if (ft_strchr(s.parser->current->value, '\n'))
				s.parser->current->value = case_new_line(&s);
		}
		if (s.parser->current->type != 1)
		{
			start_parsing_main_helper(&s, &st);
			if (check_expand_possibility(s.prev, s.parser) == 1)
				s.parser->current->value = case_expand_in_parser(&s, env);
			start_parsing_helper_1(&s.cmd, &st, s.parser);
		}
		start_parsing_helper_0(s.parser, &st, &s.cmds, &s);
	}
	return (s.cmds);
}
