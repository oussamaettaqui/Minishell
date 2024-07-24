/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:01:42 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:54:01 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstlast(t_env *list)
{
	t_env	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current->next)
		current = current->next;
	return (current);
}

t_env	*ft_lstnew(char *line, size_t pos, int check)
{
	t_env	*result;

	result = malloc(sizeof(t_env) * 1);
	if (result == NULL)
		return (NULL);
	result->key = ft_substr(line, 0, pos);
	if (line[pos] == '+')
		result->value = ft_substr(line, pos + 2, ft_strlen(line));
	else
		result->value = ft_substr(line, pos + 1, ft_strlen(line));
	result->sorted = 0;
	if (check == 0)
		result->env_member = 0;
	else
		result->env_member = 1;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_back(t_env **list, t_env *new)
{
	t_env	*node;

	if (!new || !list)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		node = ft_lstlast(*list);
		node->next = new;
	}
}

void	append_node(t_env **list, char *line, size_t pos, int check)
{
	t_env	*node;

	node = ft_lstnew(line, pos, check);
	ft_lstadd_back(list, node);
}
