/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:04:29 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:51:19 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone_cmd(t_args *lst)
{
	if (lst)
	{
		free(lst->cmd);
		free(lst);
	}
}

void	ft_lstclear_cmd(t_args **lst)
{
	t_args	*ls;

	if (!lst || !(*lst))
		return ;
	ls = *lst;
	while (ls)
	{
		ls = ls->next;
		ft_lstdelone_cmd(*lst);
		*lst = ls;
	}
}
