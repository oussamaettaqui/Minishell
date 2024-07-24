/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:21:03 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/15 15:51:52 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_error_cmds(t_cmds *cmds)
{
	t_cmds	*cmds1;

	cmds1 = cmds;
	while (cmds1)
	{
		if (cmds1->fd_in == -42 || cmds1->fd_out == -42)
		{
			cmds1->fd_in = 0;
			cmds1->fd_out = 1;
			return (1);
		}
		cmds1 = cmds1->next;
	}
	return (0);
}
