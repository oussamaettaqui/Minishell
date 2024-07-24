/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:57:03 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 17:57:10 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

unsigned long long	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	k;
	int					s;

	s = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	k = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - 48);
		if (k > LLONG_MAX && s == -1)
			return (0);
		i++;
	}
	return (k * s);
}
