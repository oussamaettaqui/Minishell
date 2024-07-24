/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchokri <bchokri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:40:20 by oettaqui          #+#    #+#             */
/*   Updated: 2024/07/17 18:57:16 by bchokri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_strncmp_here(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

static int	control_d(char *line, char *av)
{
	if (!line)
	{
		dup2(2, 1);
		printf("minishell: warning: here-document delimited ");
		printf("by end-of-file (wanted `%s')\n", av);
		return (0);
	}
	return (1);
}

int	here_doc(char *av, int infd, t_env **env, t_cmds *head)
{
	char	*line;

	line = NULL;
	infd = open_redir_here_doc(head);
	while (1)
	{
		line = readline("> ");
		if (control_d(line, av) == 0)
			return (0);
		if (ft_strncmp_here(line, av, ft_strlen(line)) == 0)
		{
			free(line);
			close(infd);
			infd = open(".here_doc", O_RDONLY, 0644);
			return (infd);
		}
		if (ft_strchr(line, '$') == 1)
		{
			line = expand_in_parser(line, env);
		}
		ft_putendl_fd(line, infd);
		free(line);
	}
	return (0);
}
