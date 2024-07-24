/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:43:51 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/13 15:47:55 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_lstsize(t_env *lst)
{
	size_t	i;
	t_env	*head;

	if (!lst)
		return (0);
	head = lst;
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
