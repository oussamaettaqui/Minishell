/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:34 by bchokri           #+#    #+#             */
/*   Updated: 2024/07/14 17:53:03 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_strings(char *str, char ch)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == ch)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ch)
			i++;
	}
	return (count);
}

static int	ft_strlene(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_word(char *str, char c)
{
	char	*result;
	int		i;
	int		len_str;

	i = 0;
	len_str = ft_strlene(str, c);
	result = malloc((len_str + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len_str)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	ft_workforsplit(char **strings, char *s, char c)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{
			strings[i] = ft_word((char *)&s[j], c);
			if (strings[i] == NULL)
				return (i);
			i++;
		}
		while (s[j] && s[j] != c)
			j++;
	}
	strings[i] = 0;
	return (-1);
}

char	**ft_split(char *s, char c)
{
	char	**strings;
	int		len_strings;
	int		i;

	if (s == NULL)
		return (NULL);
	len_strings = count_strings(s, c) + 1;
	strings = (char **)malloc(sizeof(char *) * len_strings);
	if (strings == NULL)
		return (NULL);
	i = ft_workforsplit(strings, s, c);
	if (i >= 0)
	{
		while (i > 0)
		{
			i--;
			free(strings[i]);
		}
		free(strings);
		return (NULL);
	}
	return (strings);
}
