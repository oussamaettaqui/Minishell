/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_handling_redirections.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:39:32 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 17:02:57 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_redirection_in(t_cmds *head, t_cmds **cmds, t_args *cmd,
	t_helper_st5 *st)
{
	if (!cmd->next)
	{
		st->flag = 1;
		return (error_syntax(cmds), -1);
	}
	head->fd_in = open_redir_in(head, cmd);
	if (head->fd_in == -1)
	{
		st->flag = 2;
		print_error_syntax_or_permision(cmd);
		return (-2);
	}
	return (0);
}

int	check_redirection_out(t_cmds *head, t_cmds **cmds, t_args *cmd,
	t_helper_st5 *st)
{
	if (!cmd->next)
	{
		st->flag = 1;
		return (error_syntax(cmds), -1);
	}
	head->fd_out = open_redir_out(head, cmd);
	if (head->fd_out == -1)
	{
		st->flag = 2;
		print_error_syntax_or_permision(cmd);
		return (-2);
	}
	return (0);
}

int	check_redirection_appand(t_cmds *head, t_cmds **cmds, t_args *cmd,
	t_helper_st5 *st)
{
	if (!cmd->next)
	{
		st->flag = 1;
		return (error_syntax(cmds), -1);
	}
	head->fd_out = open_redir_appand(head, cmd);
	if (head->fd_out == -1)
	{
		st->flag = 2;
		print_error_syntax_or_permision(cmd);
		return (-2);
	}
	return (0);
}
