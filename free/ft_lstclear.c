/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:47:08 by bchokri           #+#    #+#             */
/*   Updated: 2024/06/04 18:57:53 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_lstdelone(t_env *lst)
{
	if (lst)
	{
		free(lst->value);
		free(lst->key);
		free(lst);
	}
}

void	ft_lstclear(t_env **lst)
{
	t_env	*ls;

	if (lst == NULL || !*lst)
		return ;
	ls = *lst;
	while (ls)
	{
		ls = ls->next;
		ft_lstdelone(*lst);
		*lst = ls;
	}
}
