/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_cmds_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:20:56 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 15:21:23 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_lstsize_cmds_b(t_cmds *lst)
{
	size_t	i;
	t_cmds	*head;

	head = lst;
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
