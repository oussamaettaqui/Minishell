/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:18:56 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/13 18:00:29 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_array_pipes(int **array, int number_pipe)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (number_pipe > 0)
	{
		free(array[i]);
		i++;
		number_pipe--;
	}
	free(array);
}
