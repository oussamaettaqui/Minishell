/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:52:20 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:51:29 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_env *lst)
{
	if (lst)
	{
		free(lst->key);
		free(lst->value);
		free(lst);
	}
}

void	ft_lstclear_env(t_env **lst)
{
	t_env	*ls;

	if (!lst)
		return ;
	ls = *lst;
	while (ls)
	{
		ls = ls->next;
		ft_lstdelone(*lst);
		*lst = ls;
	}
}
