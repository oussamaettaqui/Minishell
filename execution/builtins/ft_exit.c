/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:17:03 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/20 15:51:08 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_chech_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static void	ft_cnd1_else(char **cmds, int i)
{
	dup2(2, 1);
	if (i == 0)
		printf("exit\n");
	printf("minishell: %s: %s: numeric argument required\n", cmds[0], cmds[1]);
	exit(2);
}

static void	ft_else_cnd(char **cmds, int i)
{
	if (ft_chech_is_num(cmds[1]) == 0 || (ft_atoi(cmds[1]) > LLONG_MAX
			&& cmds[1][0] != '-'))
	{
		ft_cnd1_else(cmds, i);
	}
	else if (ft_strlen_2char(cmds) > 2)
	{
		dup2(2, 1);
		if (i == 0)
			printf("exit\n");
		g_exit_status = 1;
		printf("minishell: %s: too many arguments\n", cmds[0]);
	}
	else
	{
		if (i == 0)
			printf("exit\n");
		g_exit_status = ft_atoi(cmds[1]);
		if (i == 0)
			exit(ft_atoi(cmds[1]));
	}
}

void	ft_exit(char **cmds, int i)
{
	if (cmds[1] == NULL)
		exit(0);
	else
		ft_else_cnd(cmds, i);
}
