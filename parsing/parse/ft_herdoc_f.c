/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:03:29 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/19 17:02:44 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sigint_here(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl_fd("> ^C", 0);
		exit(130);
	}
}

void	ft_herdoc_f(t_helper_st5 *st, t_cmds **cmds, t_env **env)
{
	int	pid_here;
	int	status;

	signal(SIGINT, SIG_IGN);
	pid_here = fork();
	if (pid_here == 0)
	{
		signal(SIGINT, sigint_here);
		st->head->fd_in = here_doc(st->cmd->next->cmd, st->head->fd_in, env,
				st->head);
		close(st->head->fd_in);
		exit(0);
	}
	while (waitpid(pid_here, &status, 0) != -1)
		;
	signal(SIGINT, SIG_IGN);
	st->head->fd_in = open(".here_doc", O_RDONLY, 0644);
	error_deleting_file_here_doc(cmds);
	g_exit_status = WEXITSTATUS(status);
	if (g_exit_status == 130)
		st->flag = 1;
}
