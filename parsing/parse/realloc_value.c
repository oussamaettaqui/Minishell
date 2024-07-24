/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:39:04 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 18:11:08 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*realloc_value(char *value)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(value));
	if (!new)
		return (NULL);
	while (value[i] && value[i] != '\n')
	{
		new[i] = value[i];
		i++;
	}
	new[i] = '\0';
	free(value);
	return (new);
}
