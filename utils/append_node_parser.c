/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:57:02 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:53:52 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parser	*ft_lstlast_parser(t_parser *list)
{
	t_parser	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current->next)
		current = current->next;
	return (current);
}

t_parser	*ft_lstnew_parser(t_token *token)
{
	t_parser	*result;

	result = malloc(sizeof(t_parser));
	if (result == NULL)
		return (NULL);
	result->current = token;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back_parser(t_parser **list, t_parser *new)
{
	t_parser	*node;

	if (!new || !list)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		node = ft_lstlast_parser(*list);
		node->next = new;
	}
}

void	append_node_parser(t_parser **list, t_token *token)
{
	t_parser	*node;

	node = ft_lstnew_parser(token);
	ft_lstadd_back_parser(list, node);
}
