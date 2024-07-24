/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:18:16 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/17 16:01:36 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_builtins(char **commands, t_exec data)
{
	if (ft_strcmp(commands[0], "echo") == 0)
		ft_echo(commands);
	else if (ft_strcmp(commands[0], "env") == 0)
		ft_env(data.env_l, commands);
	else if (ft_strcmp(commands[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(commands[0], "cd") == 0)
		ft_cd(commands, data.env_l);
	else if (ft_strcmp(commands[0], "unset") == 0)
		data.env_l = ft_unset(commands, &data.env_l);
	else if (ft_strcmp(commands[0], "export") == 0)
		ft_export(commands, data.env_l);
	else if (ft_strcmp(commands[0], "exit") == 0)
		ft_exit(commands, 1);
	else
		return (0);
	return (1);
}
