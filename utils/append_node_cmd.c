/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:53:54 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:55:56 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_args	*ft_lstlast_cmd(t_args *list)
{
	t_args	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

t_args	*ft_lstnew_cmd(char *cmd)
{
	t_args	*result;

	result = malloc(sizeof(t_args));
	if (result == NULL)
		return (NULL);
	result->cmd = ft_strdup(cmd);
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back_cmd(t_args **list, t_args *new)
{
	t_args	*node;

	if (!new || !list)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		node = ft_lstlast_cmd(*list);
		node->next = new;
	}
}

void	append_node_cmd(t_args **list, char *cmd)
{
	t_args	*node;

	node = ft_lstnew_cmd(cmd);
	ft_lstadd_back_cmd(list, node);
}
