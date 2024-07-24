/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_1_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqui <oettaqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:29:07 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/12 17:25:34 by oettaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_f	*init_flags(t_f *flags)
{
	flags = malloc(sizeof(t_f));
	flags->f = 0;
	flags->s = 0;
	return (flags);
}
