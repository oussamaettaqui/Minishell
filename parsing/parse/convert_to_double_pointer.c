/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_double_pointer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:22:24 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/15 15:52:36 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lstsize_cmd(t_args *cmd)
{
	t_args	*cmd_c;
	int		i;

	i = 0;
	if (cmd)
	{
		cmd_c = cmd;
		while (cmd_c)
		{
			cmd_c = cmd_c->next;
			i++;
		}
	}
	return (i);
}

char	**convert_to_double_pointer(t_args *cmd)
{
	int		sizeof_cmd;
	char	**res;
	t_args	*tmp;
	int		i;

	i = 0;
	tmp = cmd;
	sizeof_cmd = ft_lstsize_cmd(cmd);
	res = malloc(sizeof(char *) * (sizeof_cmd + 1));
	if (!res)
		return (NULL);
	while (i < sizeof_cmd)
	{
		res[i] = ft_strdup(tmp->cmd);
		i++;
		tmp = tmp->next;
	}
	res[i] = NULL;
	return (res);
}
