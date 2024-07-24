/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in_parser_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:14:42 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/18 17:36:10 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_exit_status(char *src, char *key)
{
	char	*status;

	status = NULL;
	status = ft_itoa(g_exit_status);
	src = ft_strjoin(src, status);
	free(status);
	free(key);
	return (src);
}

char	*expnad_dollar_only(char *src, char *key, char *s, int i)
{
	src = add_char_char(src, key[0]);
	if (s[i] == ' ')
		src = add_char_char(src, s[i]);
	free(key);
	return (src);
}

void	init_helper_st2(t_helper_st2 *st)
{
	st->v = NULL;
	st->src = NULL;
	st->key = NULL;
	st->i = 0;
}
