/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:58:32 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 21:00:21 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	read2_help(void)
{
	ft_putendl_fd("minishell: maximum here-document count exceeded", 2);
	exit(2);
}
