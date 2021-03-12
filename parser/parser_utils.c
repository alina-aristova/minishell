/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:22:19 by acase             #+#    #+#             */
/*   Updated: 2021/02/16 18:55:44 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		redirection(t_shell *shell, char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (open_redirection_r(shell, str, i) == 0)
			return (1);
		if (open_redirection_l(shell, str, i) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	init_shell_structs(t_shell *shell, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		shell[i].argv = NULL;
		shell[i].input = 0;
		shell[i].output = 1;
		i++;
	}
}

int		count_red(char **str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (is_redirectoin(*str))
			i++;
		str++;
	}
	return (i);
}

int		is_redirectoin(char *str)
{
	if (!ft_memcmp(str, ">", 2) || !ft_memcmp(str, "<", 2)
	|| !ft_memcmp(str, ">>", 3))
		return (TRUE);
	return (FALSE);
}
