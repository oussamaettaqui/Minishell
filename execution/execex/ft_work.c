/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:49:08 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/20 14:14:06 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_work3(t_exec data)
{
	int	pid3;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_p);
	signal(SIGQUIT, sig_p);
	pid3 = fork();
	if (pid3 == -1)
	{
		perror("fork");
		exit(1);
	}
	process3(data, pid3);
	return (pid3);
}

static int	ft_work2(t_exec data)
{
	int	pid2;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_p);
	signal(SIGQUIT, sig_p);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork");
		exit(1);
	}
	process2(data, pid2);
	return (pid2);
}

static int	ft_work1(t_exec data)
{
	int	pid1;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_p);
	signal(SIGQUIT, sig_p);
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		exit(1);
	}
	process1(data, pid1);
	return (pid1);
}

static int	all_works(t_exec *data, int pid2)
{
	ft_work1(*data);
	data->cmd_pos++;
	data->cmds_lst = data->cmds_lst->next;
	data->id_pipe++;
	while (data->number_cmd - 1 > data->cmd_pos)
	{
		ft_work3(*data);
		data->cmd_pos++;
		data->cmds_lst = data->cmds_lst->next;
		data->id_pipe++;
	}
	data->id_pipe--;
	if (data->number_cmd > 1)
		pid2 = ft_work2(*data);
	return (pid2);
}

void	ft_work(t_env *env, t_cmds *cmds_lst)
{
	int		status;
	int		status1;
	int		pid2;
	t_exec	data;

	pid2 = -1;
	data.cmd_pos = 0;
	data.number_cmd = ft_lstsize_cmds_b(cmds_lst);
	data.id_pipe = 0;
	data.cmds_lst = cmds_lst;
	data.env = ft_convert_env(&env);
	data.env_l = env;
	if (data.number_cmd > 1)
		data.fds = give_table_pipes(data.number_cmd - 1);
	pid2 = all_works(&data, pid2);
	free_double_pointer(data.env);
	complete_work(&data);
	if (pid2 != -1)
		waitpid(pid2, &status1, 0);
	while (waitpid(-1, &status, 0) != -1)
		;
	if (pid2 != -1)
		g_exit_status = WEXITSTATUS(status1);
	else
		g_exit_status = WEXITSTATUS(status);
}
