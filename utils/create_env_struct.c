/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:31:23 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/19 10:32:11 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_env_struct(t_env **list, char **env)
{
	int		i;
	size_t	pos;
	char	str[1024];
	char	*key;
	char	*all;

	i = 0;
	if (!env[i])
	{
		getcwd(str, sizeof(str));
		key = ft_strdup("PWD");
		all = ft_strjoin_b(key, str);
		append_node(list, all, 3, 0);
		append_node(list, "_=/usr/bin/env", 1, 0);
		free(key);
		free(all);
	}
	while (env[i])
	{
		pos = find_equal(env[i]);
		append_node(list, env[i], pos, 0);
		i++;
	}
}
