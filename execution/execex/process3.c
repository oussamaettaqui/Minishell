/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:47:11 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/19 16:58:14 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_3(char **commands)
{
	dup2(2, 1);
	if (access(commands[0], F_OK) == 0)
	{
		printf("minishell: %s: Permission denied\n", commands[0]);
		return (3);
	}
	else
		printf("minishell: %s: No such file or directory\n", commands[0]);
	return (10);
}

static int	check_path(char **commands, int val_check)
{
	dup2(2, 1);
	if (ft_strcmp(commands[0], ".") == 0)
	{
		printf("minishell: %s: ", commands[0]);
		printf("filename argument required\n");
		printf(".: usage: . filename [arguments]\n");
		return (2);
	}
	else if (val_check == 4)
	{
		printf("bash: %s: Is a directory\n", commands[0]);
		return (3);
	}
	else
		printf("%s: command not found\n", commands[0]);
	return (10);
}

static void	check_0(char **commands, t_exec data, char *path, char **paths)
{
	int	val_check;
	int	check;

	check = 0;
	val_check = check_command(paths, commands, data.env);
	if (val_check == 1 || val_check == 3 || val_check == 4)
	{
		if (val_check == 3)
			check = check_3(commands);
		else if (path)
			check = check_path(commands, val_check);
		if (data.number_cmd != 1)
			free_array_pipes(data.fds, data.number_cmd - 1);
		free_double_pointer(commands);
		free_double_pointer(paths);
		if (check == 2)
			exit(2);
		else if (check == 3)
			exit(126);
		exit(127);
	}
}

static void	help_process3(t_exec data)
{
	char	**commands;
	char	*path;
	char	**paths;
	int		check;

	check = 0;
	commands = convert_to_double_pointer(data.cmds_lst->cmd);
	if (!commands[0])
	{
		free_double_pointer(commands);
		return ;
	}
	if (ft_strlen(commands[0]) == 0)
	{
		free(commands[0]);
		commands[0] = ft_strdup("\'\'");
	}
	path = get_path(data.env);
	check = check_builtins(commands, data);
	paths = ft_split(path, ':');
	if (check == 0)
		check_0(commands, data, path, paths);
	free_double_pointer(commands);
	free_double_pointer(paths);
}

void	process3(t_exec data, int pid3)
{
	if (pid3 == 0)
	{
		if (data.cmds_lst->fd_out == -1 || data.cmds_lst->fd_in == -1)
			exit(1);
		if (data.cmds_lst->fd_out != 1)
			dup2(data.cmds_lst->fd_out, 1);
		else
			dup2(data.fds[data.id_pipe][1], data.cmds_lst->fd_out);
		if (data.cmds_lst->fd_in != 0)
			dup2(data.cmds_lst->fd_in, 0);
		else
			dup2(data.fds[data.id_pipe - 1][0], 0);
		close_fds(data);
		help_process3(data);
		close(data.cmds_lst->fd_out);
		close(data.cmds_lst->fd_in);
		exit(g_exit_status);
	}
}
