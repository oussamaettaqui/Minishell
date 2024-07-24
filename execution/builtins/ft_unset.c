/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:28:42 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/17 17:04:48 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_lstdelone(t_env *lst)
{
	if (lst)
	{
		free(lst->value);
		free(lst->key);
		free(lst);
	}
}

static t_env	*ft_get_behind(t_env *env, char *key)
{
	t_env	*current;

	if (!env)
		return (NULL);
	current = env;
	while (current->next)
	{
		if (strcmp(key, current->next->key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	ft_unset_work(char **cmds, size_t i, t_env **env)
{
	t_env	*element;
	t_env	*behind;

	element = ft_get_key(*env, cmds[i]);
	behind = ft_get_behind(*env, cmds[i]);
	if (element)
	{
		if (behind)
			behind->next = element->next;
		else
		{
			if (element->next)
				*env = element->next;
			else
				*env = NULL;
		}
		ft_lstdelone(element);
	}
}

t_env	*ft_unset(char **cmds, t_env **env)
{
	size_t	i;

	i = 1;
	while (cmds[i])
	{
		if (ft_strcmp(cmds[i], "_") != 0)
			ft_unset_work(cmds, i, env);
		i++;
	}
	g_exit_status = 0;
	return (*env);
}
