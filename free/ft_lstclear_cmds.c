/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:18:42 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:51:24 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone_cmds(t_cmds *lst)
{
	if (lst)
	{
		ft_lstclear_cmd(&lst->cmd);
		free(lst);
	}
}

void	ft_lstclear_cmds(t_cmds **lst)
{
	t_cmds	*ls;

	if (!lst || !(*lst))
		return ;
	ls = *lst;
	while (ls)
	{
		ls = ls->next;
		ft_lstdelone_cmds(*lst);
		*lst = ls;
	}
	*lst = NULL;
}
