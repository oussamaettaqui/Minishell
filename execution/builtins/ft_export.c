/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:05:16 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/17 21:46:18 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_valid1(char **cmds, t_export_st *vars, int i)
{
	if (cmds[i][vars->pos] == '+')
	{
		vars->str = ft_substr(cmds[i], vars->pos + 2, ft_strlen(cmds[i]));
		vars->value = ft_strjoin_b(vars->element->value, vars->str);
		free(vars->element->value);
		vars->element->value = vars->value;
		free(vars->str);
	}
	else
	{
		free(vars->element->value);
		vars->element->value = ft_substr(cmds[i], vars->pos + 1,
				ft_strlen(cmds[i]));
	}
	if (vars->pos != ft_strlen(cmds[i]))
		vars->element->env_member = 0;
}

static void	ft_valid(char **cmds, t_export_st *vars, int i, t_env *env)
{
	if (vars->element)
		ft_valid1(cmds, vars, i);
	else
	{
		if (check_equal(cmds[i]) == 0)
			append_node(&env, cmds[i], vars->pos, 0);
		else
			append_node(&env, cmds[i], vars->pos, 1);
	}
	free(vars->key);
	g_exit_status = 0;
}

static void	ft_notvalid1(char **cmds, int i)
{
	dup2(2, 1);
	printf("minishel: export: `%s': not a valid identifier\n", cmds[i]);
	g_exit_status = 1;
}

static void	ft_notvalid2(char **cmds, int i)
{
	dup2(2, 1);
	printf("minishel: export: %c%c: invalid option\n", cmds[i][0], cmds[i][1]);
	printf("export: usage: export [-fn] [name[=value] ...] or export -p\n");
	g_exit_status = 2;
}

void	ft_export(char **cmds, t_env *env)
{
	size_t		i;
	t_export_st	vars;

	if (ft_strlen_2char(cmds) == 1)
	{
		ft_display_env_sorted(env);
		g_exit_status = 0;
	}
	i = 1;
	vars.value = NULL;
	while (cmds[i])
	{
		if (check_valid(cmds[i]) == 1 || ft_strcmp(cmds[i], "") == 0)
			ft_notvalid1(cmds, i);
		else if (check_valid(cmds[i]) == 2)
			ft_notvalid2(cmds, i);
		else
		{
			vars.pos = find_equal(cmds[i]);
			vars.key = ft_substr(cmds[i], 0, vars.pos);
			vars.element = ft_get_key(env, vars.key);
			ft_valid(cmds, &vars, i, env);
		}
		i++;
	}
}
