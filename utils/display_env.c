/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:56:29 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:53:46 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	display_env(t_env *list)
{
	t_env	*current;

	if (!list)
		printf("empty env");
	current = list;
	while (current)
	{
		if (current->env_member == 0)
		{
			printf("%s=", current->key);
			printf("%s\n", current->value);
		}
		current = current->next;
	}
}
