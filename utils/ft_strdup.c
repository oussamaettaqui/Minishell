/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:47:17 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 17:52:51 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(char *s1)
{
	char	*copie;
	int		i;
	int		len_s1;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	copie = malloc((len_s1 + 1) * sizeof(char));
	if (copie == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copie[i] = s1[i];
		i++;
	}
	copie[i] = '\0';
	return (copie);
}
