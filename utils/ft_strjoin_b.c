/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:58:01 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 17:58:08 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	helpshoin(char *s1, char *s2, char *result, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
		{
			result[i] = s1[i];
			i++;
		}
		else
		{
			result[i] = s2[j];
			i++;
			j++;
		}
	}
	result[i] = '\0';
}

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*result;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	helpshoin(s1, s2, result, len);
	return (result);
}
