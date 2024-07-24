/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:03:46 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 15:34:29 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	open_redir_in(t_cmds *head, t_args *cmd)
{
	if (head->fd_in != 0)
		close(head->fd_in);
	head->fd_in = open(cmd->next->cmd, O_RDONLY);
	return (head->fd_in);
}

int	open_redir_out(t_cmds *head, t_args *cmd)
{
	if (head->fd_out != 1)
		close(head->fd_out);
	head->fd_out = open(cmd->next->cmd, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (head->fd_out);
}

int	open_redir_appand(t_cmds *head, t_args *cmd)
{
	if (head->fd_out != 1)
		close(head->fd_out);
	head->fd_out = open(cmd->next->cmd, O_CREAT | O_RDWR | O_APPEND, 0644);
	return (head->fd_out);
}

int	open_redir_here_doc(t_cmds *head)
{
	if (head->fd_in != 0)
		close(head->fd_in);
	head->fd_in = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (head->fd_in);
}
