/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:18:44 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/20 14:34:23 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sig_p(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_exit_status = 130;
	}
	else if (sig == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		g_exit_status = 131;
	}
}
