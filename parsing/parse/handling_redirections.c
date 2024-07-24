/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:22:58 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 18:45:24 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_args	*ft_get_prev(t_args *cmd)
{
	t_args	*current;

	if (!cmd)
		return (NULL);
	current = cmd;
	while (current->next)
	{
		if (condition_redirec_in(current, cmd) == 1)
			return (current);
		else if (condition_redirec_out(current, cmd) == 1)
			return (current);
		else if (condition_redirec_app(current, cmd) == 1)
			return (current);
		else if (condition_redirec_here(current, cmd) == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_args	*ft_get_redirection(t_args *cmd)
{
	t_args	*current;

	if (!cmd)
		return (NULL);
	current = cmd;
	while (current)
	{
		if (ft_strcmp("<", current->cmd) == 0)
			return (current);
		else if (ft_strcmp(">", current->cmd) == 0)
			return (current);
		else if (ft_strcmp(">>", current->cmd) == 0)
			return (current);
		else if (ft_strcmp("<<", current->cmd) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_cmds	*handling_redirections(t_cmds **cmds, t_env **env)
{
	t_helper_st5	st;

	init_t_helper_st5(cmds, &st);
	while (st.head)
	{
		helper_function_2(&st);
		while (st.cmd)
		{
			helper_function_3(&st, cmds, env);
			if (st.flag == 1)
			{
				ft_lstclear_cmds(cmds);
				return (NULL);
			}
			else if (st.flag == 2)
				break ;
			helper_function_1(&st);
		}
		st.head = st.head->next;
	}
	return (*cmds);
}
