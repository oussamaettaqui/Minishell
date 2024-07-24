/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:12:32 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/19 17:39:20 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

int	main(int ac, char **av, char **env)
{
	int	value;

	(void)av;
	welcom();
	value = ft_read(ac, env);
	return (value);
}
