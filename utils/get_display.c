/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:29:28 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 18:38:36 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_display(void)
{
	char	str[1024];
	char	*display;
	char	*pwd;

	if (getcwd(str, sizeof(str)) != NULL)
	{
		pwd = ft_strjoin_b(str, "$ ");
		display = ft_strjoin_b("minishell-1.0~", pwd);
		free(pwd);
	}
	else
		display = ft_strjoin_b("minishell-1.0.", "$ \0");
	return (display);
}
