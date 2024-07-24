/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirections_helper.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:29:16 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 17:06:22 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	condition_redirec_in(t_args *current, t_args *cmd)
{
	if (ft_strcmp("<", current->next->cmd) == 0 && ft_strcmp("<", cmd->cmd) != 0
		&& ft_strcmp(">", cmd->cmd) != 0 && ft_strcmp(">>", cmd->cmd) != 0
		&& ft_strcmp("<<", cmd->cmd) != 0)
	{
		return (1);
	}
	return (0);
}

int	condition_redirec_out(t_args *current, t_args *cmd)
{
	if (ft_strcmp(">", current->next->cmd) == 0 && ft_strcmp(">", cmd->cmd) != 0
		&& ft_strcmp("<", cmd->cmd) != 0 && ft_strcmp(">>", cmd->cmd) != 0
		&& ft_strcmp("<<", cmd->cmd) != 0)
	{
		return (1);
	}
	return (0);
}

int	condition_redirec_app(t_args *current, t_args *cmd)
{
	if (ft_strcmp(">>", current->next->cmd) == 0 && ft_strcmp(">",
			cmd->cmd) != 0 && ft_strcmp("<", cmd->cmd) != 0 && ft_strcmp(">>",
			cmd->cmd) != 0 && ft_strcmp("<<", cmd->cmd) != 0)
	{
		return (1);
	}
	return (0);
}

int	condition_redirec_here(t_args *current, t_args *cmd)
{
	if (ft_strcmp("<<", current->next->cmd) == 0 && ft_strcmp(">",
			cmd->cmd) != 0 && ft_strcmp("<", cmd->cmd) != 0 && ft_strcmp(">>",
			cmd->cmd) != 0 && ft_strcmp("<<", cmd->cmd) != 0)
	{
		return (1);
	}
	return (0);
}

void	error_syntax(t_cmds **cmds)
{
	printf("minishell: syntax error near unexpected token `newline'\n");
	g_exit_status = 2;
	ft_lstclear_cmds(cmds);
}
