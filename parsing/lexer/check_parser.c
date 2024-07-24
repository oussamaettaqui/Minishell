/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:15:03 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:21 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	msg(char *token_value)
{
	g_exit_status = 2;
	printf("minishell: syntax error near unexpected token ");
	printf("'%s\'\n", token_value);
}

int	check_parser_0(t_parser *head, int current_type)
{
	while (head && head->current->type != 6 && head->current->type != 7
		&& head->current->type != 8)
	{
		if (current_type != 0 && current_type != 7 && current_type != 8
			&& head->current->type == 1)
		{
			msg(head->current->value);
			return (1);
		}
		else if ((current_type != 0 && head->current->type != 0
				&& current_type != 8) && current_type != 1)
		{
			msg(head->current->value);
			return (1);
		}
		current_type = head->current->type;
		if (head->next == NULL && current_type != 0 && current_type != 8)
		{
			msg(head->current->value);
			return (1);
		}
		head = head->next;
	}
	return (0);
}

int	check_parser(t_parser **parser, t_env **env)
{
	t_parser		*head;
	t_token_type	current_type;

	head = (*parser);
	(void)env;
	current_type = 0;
	if (head)
	{
		if (head->current->type == 1)
		{
			msg(head->current->value);
			return (1);
		}
		current_type = head->current->type;
		head = head->next;
		return (check_parser_0(head, current_type));
	}
	return (1);
}
