/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_env_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:04:58 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/20 15:28:01 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_back_unsorted(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		current->sorted = 0;
		current = current->next;
	}
}

static size_t	display(t_env *current, size_t i)
{
	if (current->env_member == 0)
	{
		printf("declare -x %s=", current->key);
		printf("\"%s\"\n", current->value);
	}
	else
	{
		printf("declare -x %s", current->key);
		printf("\n");
	}
	current->sorted = 1;
	i++;
	return (i);
}

static size_t	ft_sort_element(t_env *env, t_env *current, t_env *element,
		int i)
{
	while (current)
	{
		element = env;
		while (element && current->sorted == 0)
		{
			if (ft_strcmp(current->key, element->key) > 0
				&& element->sorted == 0)
				break ;
			else
				element = element->next;
		}
		if (!element)
			i = display(current, i);
		current = current->next;
	}
	return (i);
}

void	ft_display_env_sorted(t_env *env)
{
	t_env	*current;
	t_env	*element;
	t_env	*keep_it_sorted;
	size_t	i;

	if (!env)
		return ;
	keep_it_sorted = ft_get_key(env, "_");
	keep_it_sorted->sorted = 1;
	element = NULL;
	i = 0;
	while (i < ft_lstsize(env) - 1)
	{
		current = env;
		i = ft_sort_element(env, current, element, i);
	}
	ft_back_unsorted(env);
}
