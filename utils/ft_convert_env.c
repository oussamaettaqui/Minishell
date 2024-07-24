/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:11:24 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 17:53:33 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_convert_env(t_env **env)
{
	char	**env_char;
	size_t	len_env;
	t_env	*current;
	char	*str;
	size_t	i;

	len_env = ft_lstsize(*env);
	env_char = malloc(sizeof(char *) * (len_env + 1));
	current = *env;
	i = 0;
	if (!env_char || len_env == 0)
		return (NULL);
	while (current)
	{
		str = ft_strjoin_b(current->key, "=\0");
		env_char[i] = ft_strjoin_b(str, current->value);
		free(str);
		current = current->next;
		i++;
	}
	env_char[i] = NULL;
	return (env_char);
}
