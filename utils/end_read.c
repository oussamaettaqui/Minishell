/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:53:30 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/19 13:21:39 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	end_read(t_read_st *vars)
{
	ft_lstclear_env(&vars->list);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
