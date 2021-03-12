/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:28:23 by acase             #+#    #+#             */
/*   Updated: 2021/02/16 20:10:15 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int		open_redirection_r(t_shell *shell, char **str, int i)
{
	int	fd;

	fd = 0;
	if (!memcmp(str[i], ">", 2))
	{
		if ((fd = open(str[i + 1], O_CREAT | O_WRONLY | O_TRUNC,
							0644)) < 0)
			return (sh_putstr_fd("minishell: Permission denied\n", 2));
		if (shell->output != 1)
			close(shell->output);
		shell->output = fd;
		i++;
	}
	if (!memcmp(str[i], ">>", 3))
	{
		if ((fd = open(str[i + 1], O_CREAT | O_WRONLY | O_APPEND,
							0644)) < 0)
			return (sh_putstr_fd("minishell: Permission denied\n", 2));
		if (shell->output != 1)
			close(shell->output);
		shell->output = fd;
		i++;
	}
	return (1);
}

int		open_redirection_l(t_shell *shell, char **str, int i)
{
	int	fd;

	fd = 0;
	if (!memcmp(str[i], "<", 2))
	{
		if ((fd = open(str[i + 1], O_RDONLY)) < 0)
			return (sh_putstr_fd("minishell: Permission denied\n", 2));
		if (shell->input != 0)
			close(shell->input);
		shell->input = fd;
		i++;
	}
	return (1);
}
