/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:13:30 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/13 17:57:37 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	work_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

static int	help_check_command(char **commands, char **env)
{
	if (access(commands[0], X_OK) == 0)
	{
		if (execve(commands[0], commands, env) == -1)
		{
			if (work_check(commands[0]) == 0)
				return (4);
			else
				return (1);
		}
		return (0);
	}
	else if (work_check(commands[0]) == 0)
		return (3);
	return (2);
}

static int	null_cmds(char **commands)
{
	if (!commands)
		return (2);
	if (!commands[0])
		return (1);
	return (0);
}

int	check_command(char **paths, char **commands, char **env)
{
	char	*file_exucute;
	int		i;
	int		r;

	i = -1;
	if (null_cmds(commands) != 0)
		return (null_cmds(commands));
	r = help_check_command(commands, env);
	if (r == 1 || r == 0 || r == 3 || r == 4)
		return (r);
	if (!paths)
		return (3);
	while (paths[++i])
	{
		file_exucute = ft_strjoin_b_exec(paths[i], commands[0]);
		if (access(file_exucute, X_OK) == 0)
		{
			if (execve(file_exucute, commands, env) == -1)
				return (1);
			return (0);
		}
		free(file_exucute);
	}
	return (1);
}
