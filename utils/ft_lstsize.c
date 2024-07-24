/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:06:59 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:57:31 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize_parser(t_parser *lst)
{
	int			i;
	t_parser	*ls;

	i = 0;
	ls = lst;
	while (ls)
	{
		i++;
		ls = ls->next;
	}
	return (i);
}

int	ft_lstsize_cmds(t_cmds *lst)
{
	int		i;
	t_cmds	*ls;

	i = 0;
	ls = lst;
	while (ls)
	{
		i++;
		ls = ls->next;
	}
	return (i);
}
