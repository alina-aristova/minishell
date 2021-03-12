/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 04:01:32 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/09 04:01:37 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char		*line;
	int			code;
	t_execv		exec;
	t_all		all;

	exec.exit_status = 0;
	exec.envp = reallocate_envp(envp);
	exec.stdin_back = dup(0);
	exec.stdout_back = dup(1);
	if (exec.stdout_back == -1 || exec.stdin_back == -1)
		dup_fail();
	(void)argc;
	(void)argv;
	signal_init();
	code = 0;
	while (1)
	{
		ft_putstr_fd("minishell> ", 2);
		shell_read(&line, code);
		code = parser(line, &all, &exec, code);
		free(line);
	}
	exit(0);
}
