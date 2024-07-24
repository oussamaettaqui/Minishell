/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:53:13 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/24 13:02:05 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	read0(t_read_st *vars)
{
	ft_lstclear_env(&vars->list);
	ft_lstclear_parser(&vars->parser);
	free(vars->display);
	ft_lstclear_cmds(&vars->cmds);
	printf("exit\n");
}

static void	read_1(t_read_st *vars)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	vars->display = get_display();
	vars->line = readline("\033[1;33m  → minishell~$\033[1;0m");
}

static void	read2(t_read_st *vars)
{
	if ((ft_strchr(vars->line, '\n') != 0 || vars->line[0] != '\0'))
		add_history(vars->line);
	if ((ft_strchr(vars->line, '\n') != 0 || vars->line[0] != '\0')
		|| !vars->line)
	{
		vars->f = 1;
		vars->parser = initialize_parser(vars->line, &vars->list);
		if (!vars->parser)
			vars->f = 0;
		if (vars->f != 0)
		{
			vars->cmds = start_parsing(vars->parser, &vars->list);
			if (!vars->cmds)
				read2_help();
			if (check_error_cmds(vars->cmds) != 1)
			{
				vars->cmds = handling_redirections(&vars->cmds, &vars->list);
				if (vars->cmds)
					vars->list = ft_exec(vars->list, vars->cmds);
			}
		}
	}
}

static void	read3(t_read_st *vars)
{
	free(vars->line);
	free(vars->display);
	ft_lstclear_parser(&vars->parser);
	ft_lstclear_cmds(&vars->cmds);
}

int	ft_read(int ac, char **env)
{
	t_read_st	vars;

	vars.list = NULL;
	vars.parser = NULL;
	vars.cmds = NULL;
	vars.f = 1;
	if (ac == 1)
	{
		create_env_struct(&vars.list, env);
		while (1)
		{
			read_1(&vars);
			if (vars.line == NULL)
			{
				read0(&vars);
				break ;
			}
			read2(&vars);
			read3(&vars);
		}
		end_read(&vars);
		return (0);
	}
	return (1);
}
