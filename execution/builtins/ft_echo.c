/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:16:31 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/17 17:03:59 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_putendl(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

static int	ft_check_option(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (-1);
	if (s[i] && s[i] == '-')
		i++;
	while (s[i] && s[i] == 'n')
		i++;
	return (i);
}

static size_t	ft_count_elements(char **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

void	ft_echo(char **cmds)
{
	size_t	i;
	int		pass_options;
	int		exist_option;

	i = 1;
	pass_options = 0;
	exist_option = 0;
	while (cmds[i])
	{
		if ((ft_check_option(cmds[i]) == (int)ft_strlen(cmds[i]))
			&& pass_options == 0)
			exist_option = 1;
		else if (i < ft_count_elements(cmds) - 1)
		{
			pass_options = 1;
			ft_putendl(cmds[i]);
			write(1, " ", 1);
		}
		else
			ft_putendl(cmds[i]);
		i++;
	}
	if (exist_option != 1)
		write(1, "\n", 1);
	g_exit_status = 0;
}
