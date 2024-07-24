/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirections_helper_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:19:05 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 18:44:39 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_lstdelone(t_args *lst)
{
	if (lst)
	{
		free(lst->cmd);
		free(lst);
	}
}

void	helper_function_1(t_helper_st5 *st)
{
	if (st->prev)
		st->prev->next = st->cmd->next->next;
	else
		st->head->cmd = update_head(st->head, st->cmd);
	st->cmd_next = st->cmd->next;
	ft_lstdelone(st->cmd);
	ft_lstdelone(st->cmd_next);
	st->cmd = ft_get_redirection(st->head->cmd);
	st->prev = ft_get_prev(st->head->cmd);
}

void	helper_function_2(t_helper_st5 *st)
{
	st->flag = 0;
	st->cmd = ft_get_redirection(st->head->cmd);
	st->prev = ft_get_prev(st->head->cmd);
}

void	helper_function_3(t_helper_st5 *st, t_cmds **cmds, t_env **env)
{
	if (ft_strcmp(st->cmd->cmd, "<") == 0)
		check_redirection_in(st->head, cmds, st->cmd, st);
	else if (ft_strcmp(st->cmd->cmd, ">") == 0)
		check_redirection_out(st->head, cmds, st->cmd, st);
	else if (ft_strcmp(st->cmd->cmd, ">>") == 0)
		check_redirection_appand(st->head, cmds, st->cmd, st);
	else if (ft_strcmp(st->cmd->cmd, "<<") == 0)
	{
		if (!st->cmd->next)
		{
			error_syntax(cmds);
			st->flag = 1;
		}
		ft_herdoc_f(st, cmds, env);
	}
}
