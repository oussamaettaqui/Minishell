/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:47:19 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/17 17:03:53 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	check_cnd1(char **cmds, t_cd_struct *vars)
{
	if (vars->home)
	{
		chdir(vars->home->value);
		if (vars->pwd)
		{
			free(vars->pwd->value);
			getcwd(vars->str, sizeof(vars->str));
			vars->pwd->value = ft_strdup(vars->str);
		}
		if (vars->oldpwd)
		{
			free(vars->oldpwd->value);
			vars->oldpwd->value = ft_strdup(vars->str1);
		}
	}
	else
	{
		dup2(2, 1);
		printf("minishell: %s: HOME not set\n", cmds[0]);
		vars->check = 1;
	}
}

static void	check_cnd2(t_cd_struct *vars)
{
	if (vars->pwd)
	{
		free(vars->pwd->value);
		getcwd(vars->str, sizeof(vars->str));
		vars->pwd->value = ft_strdup(vars->str);
	}
	if (vars->oldpwd)
	{
		free(vars->oldpwd->value);
		vars->oldpwd->value = ft_strdup(vars->str1);
	}
}

static void	check_cnd3(char **cmds, t_cd_struct *vars)
{
	if (vars->oldpwd)
	{
		chdir(vars->oldpwd->value);
		printf("%s\n", vars->oldpwd->value);
		if (vars->pwd)
		{
			free(vars->pwd->value);
			getcwd(vars->str, sizeof(vars->str));
			vars->pwd->value = ft_strdup(vars->str);
		}
		free(vars->oldpwd->value);
		vars->oldpwd->value = ft_strdup(vars->str1);
	}
	else
	{
		dup2(2, 1);
		printf("minishell: %s: OLDPWD not set\n", cmds[0]);
		vars->check = 1;
	}
}

static void	check_cnd(char **cmds, t_cd_struct *vars)
{
	if (cmds[1] == NULL)
		check_cnd1(cmds, vars);
	else if (chdir(cmds[1]) == 0)
		check_cnd2(vars);
	else if (ft_strcmp(cmds[1], "-") == 0)
		check_cnd3(cmds, vars);
	else
	{
		dup2(2, 1);
		if (ft_strcmp(cmds[1], "\r") == 0)
			printf("minishell: %s: HOME not set\n", cmds[0]);
		else if (ft_strcmp(cmds[1], "") != 0)
			printf("minishell: %s: %s: No such file or directory\n", cmds[0],
				cmds[1]);
		vars->check = 1;
	}
}

void	ft_cd(char **cmds, t_env *env)
{
	t_cd_struct	vars;

	vars.pwd = ft_get_key(env, "PWD");
	vars.home = ft_get_key(env, "HOME");
	vars.oldpwd = ft_get_key(env, "OLDPWD");
	vars.check = 0;
	getcwd(vars.str1, sizeof(vars.str1));
	if (ft_strlen_2char(cmds) > 2)
	{
		dup2(2, 1);
		printf("minishell: %s: too many arguments\n", cmds[0]);
		vars.check = 1;
	}
	else
		check_cnd(cmds, &vars);
	if (vars.check == 1)
		g_exit_status = 1;
	else
		g_exit_status = 0;
}
