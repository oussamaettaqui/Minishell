/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:45:00 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/13 11:50:51 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ft_get_key(t_env *env, char *key)
{
	t_env	*current;

	if (!env)
		return (NULL);
	current = env;
	while (current)
	{
		if (strcmp(key, current->key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
