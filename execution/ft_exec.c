/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:02:35 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/18 17:37:36 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_exec(t_env *env, t_cmds *cmds)
{
	char	**cmd;

	cmd = convert_to_double_pointer(cmds->cmd);
	if (ft_lstsize_cmds_b(cmds) == 1 && (ft_strcmp(cmd[0], "cd") == 0
			|| ft_strcmp(cmd[0], "unset") == 0 || ft_strcmp(cmd[0],
				"export") == 0 || ft_strcmp(cmd[0], "exit") == 0))
	{
		if (cmd[0] && ft_strcmp(cmd[0], "cd") == 0)
			ft_cd(cmd, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "unset") == 0)
			env = ft_unset(cmd, &env);
		else if (cmd[0] && ft_strcmp(cmd[0], "export") == 0)
			ft_export(cmd, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "exit") == 0)
			ft_exit(cmd, 0);
	}
	else
		ft_work(env, cmds);
	free_double_pointer(cmd);
	return (env);
}
