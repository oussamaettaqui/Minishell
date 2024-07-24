/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:09:02 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:51:33 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone_parser(t_parser *lst)
{
	if (lst)
	{
		free(lst->current->value);
		free(lst->current);
		free(lst);
	}
}

void	ft_lstclear_parser(t_parser **lst)
{
	t_parser	*ls;

	if (!lst || !(*lst))
		return ;
	ls = *lst;
	while (ls)
	{
		ls = ls->next;
		ft_lstdelone_parser(*lst);
		*lst = ls;
	}
}
