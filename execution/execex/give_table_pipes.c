/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_table_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:32:34 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/13 18:07:32 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	*array_child(int size)
{
	int	*fd;

	fd = malloc(sizeof(int) * size);
	if (!fd)
		return (NULL);
	return (fd);
}

int	**give_table_pipes(int number_cmd)
{
	int	**fds;
	int	i;

	i = 0;
	fds = malloc(sizeof(int *) * (number_cmd));
	if (!fds)
		return (NULL);
	while (i < number_cmd)
	{
		fds[i] = array_child(2);
		if (pipe(fds[i]) == -1)
		{
			perror("pipe");
			exit(1);
		}
		i++;
	}
	return (fds);
}
