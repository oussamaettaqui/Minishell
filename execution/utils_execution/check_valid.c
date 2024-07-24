/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:07:42 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/13 16:08:14 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && ((str[i] >= 48 && str[i] <= 57) || str[i] == '='))
		return (1);
	else if (str[i] == '-')
		return (2);
	while (str[i] && ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97
				&& str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)
			|| str[i] == '_'))
		i++;
	if (str[i] && str[i] == '+' && str[i + 1] == '=')
		return (0);
	else if (str[i] == '\0')
		return (0);
	else if (str[i] != '=')
		return (1);
	return (0);
}
