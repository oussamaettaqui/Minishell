/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirections_main_helper.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:11:57 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 17:06:26 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error_syntax(t_args *cmd)
{
	char	*msg;
	char	*msg2;

	msg = ft_strdup("minishell: ");
	msg2 = ft_strdup(": No such file or directory");
	msg = ft_strjoin(msg, cmd->next->cmd);
	msg = ft_strjoin(msg, msg2);
	ft_putendl_fd(msg, 2);
	free(msg);
	free(msg2);
	g_exit_status = 1;
}

void	print_error_syntax_or_permision(t_args *cmd)
{
	char	*msg;
	char	*msg2;

	msg = NULL;
	msg2 = NULL;
	if (access(cmd->next->cmd, F_OK) == 0)
	{
		msg = ft_strdup("minishell: ");
		msg2 = ft_strdup(":  Permission denied");
		msg = ft_strjoin(msg, cmd->next->cmd);
		msg = ft_strjoin(msg, msg2);
		ft_putendl_fd(msg, 2);
		free(msg);
		free(msg2);
	}
	else
		print_error_syntax(cmd);
}

void	error_deleting_file_here_doc(t_cmds **cmds)
{
	if (unlink(".here_doc") == -1)
	{
		ft_putendl_fd("Error Deleting File", 2);
		ft_lstclear_cmds(cmds);
		exit(1);
	}
}

t_args	*update_head(t_cmds *head, t_args *cmd)
{
	if (cmd->next->next)
		head->cmd = cmd->next->next;
	else
		head->cmd = NULL;
	return (head->cmd);
}

void	init_t_helper_st5(t_cmds **cmds, t_helper_st5 *st)
{
	st->head = *cmds;
	st->cmd = NULL;
	st->cmd_next = NULL;
	st->prev = NULL;
	st->flag = 0;
}
