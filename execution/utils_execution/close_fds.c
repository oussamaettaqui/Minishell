/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:20:44 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 14:46:49 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_fds(t_exec data)
{
	int	i;

	i = 0;
	if (data.number_cmd > 1)
	{
		while (i < data.number_cmd - 1)
		{
			close(data.fds[i][0]);
			close(data.fds[i++][1]);
		}
	}
}
