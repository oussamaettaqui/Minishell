/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:22:33 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 15:25:07 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	complete_work(t_exec *data)
{
	int	i;

	i = 0;
	if (data->number_cmd != 1)
	{
		while (i < data->number_cmd - 1)
		{
			close(data->fds[i][0]);
			close(data->fds[i][1]);
			i++;
		}
		free_array_pipes(data->fds, data->number_cmd - 1);
	}
}
