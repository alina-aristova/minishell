/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 04:00:14 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/09 04:00:25 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_minishell.h"
#include "libft.h"
#include <stdlib.h>

void	signal_proc(int signal)
{
	(void)signal;
}

void	signal_quit_fork(int signal)
{
	char *exit_code;

	exit_code = ft_itoa(signal);
	ft_putstr_fd("Quit: ", 2);
	ft_putendl_fd(exit_code, 2);
	free(exit_code);
}

void	signal_int(int signal)
{
	(void)signal;
	ft_putstr_fd("\b\b  \b\b", 2);
	ft_putstr_fd("\nminishell> ", 2);
}

void	signal_quit(int signal)
{
	(void)signal;
	ft_putstr_fd("\b\b  \b\b", 2);
}

void	signal_init(void)
{
	signal(SIGINT, signal_int);
	signal(SIGQUIT, signal_quit);
}
