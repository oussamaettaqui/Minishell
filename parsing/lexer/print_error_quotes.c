/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:31:16 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:49 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error_quotes(int f, t_token *prev_token)
{
	g_exit_status = 2;
	if (f == 1)
	{
		printf("minishell: unexpected EOF while looking for matching `\'' \n");
		printf("minishell: syntax error: unexpected end of file \n");
	}
	else if (f == 2)
	{
		printf("minishell: unexpected EOF while looking for matching `\"' \n");
		printf("minishell: syntax error: unexpected end of file \n");
	}
	if (prev_token)
		prev_token->type = 7;
}
