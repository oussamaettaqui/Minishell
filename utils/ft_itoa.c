/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:41:34 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/14 17:53:23 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static long	len_n(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_itoa_2(char *res, long nb, long len)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		res[i++] = '-';
	}
	if (nb == 0)
		res[i++] = '0';
	while (nb > 0)
	{
		res[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
		i++;
	}
	res[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*res;
	long	len;
	long	nb;

	nb = n;
	len = len_n(nb);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	ft_itoa_2(res, nb, len);
	return (res);
}
