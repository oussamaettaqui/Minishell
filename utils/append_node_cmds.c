/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:58:55 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:56:40 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmds	*ft_lstlast_cmds(t_cmds *list)
{
	t_cmds	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

t_cmds	*ft_lstnew_cmds(t_args *cmd, int fd_in, int fd_out)
{
	t_cmds	*result;

	result = malloc(sizeof(t_cmds));
	if (result == NULL)
		return (NULL);
	result->cmd = cmd;
	result->fd_in = fd_in;
	result->fd_out = fd_out;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back_cmds(t_cmds **list, t_cmds *new)
{
	t_cmds	*node;

	if (!new || !list)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		node = ft_lstlast_cmds(*list);
		node->next = new;
	}
}

void	append_node_cmds(t_cmds **list, t_args *cmd, int *fd_in, int *fd_out)
{
	t_cmds	*node;

	node = ft_lstnew_cmds(cmd, *fd_in, *fd_out);
	ft_lstadd_back_cmds(list, node);
}
