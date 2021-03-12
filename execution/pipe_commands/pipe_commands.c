/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:19:22 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:11:28 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		get_exit_status_pipe(int *status)
{
	if (WIFEXITED(*status))
		*status = (WEXITSTATUS(*status));
	else if (WIFSIGNALED(*status))
	{
		*status = WTERMSIG(*status) + 128;
	}
}

void		exec_command_pipe(t_execv *all, t_shell *command,
						int num, int *pipefd)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_fork();
	else if (pid == 0)
	{
		pipe_red_solver(command, num, pipefd, all->count_pipe + 1);
		close_all_pipes(pipefd, all->count_pipe);
		if (command[num].argv[0][0] == '\0')
		{
			ft_putendl_fd("minishell: : command not found", 2);
			exit(127);
		}
		if ((status = is_build_in(command[num].argv[0])))
			status = execute_pipe_build_in(all, &(command[num]), 1, status);
		else if (command[num].argv[0][0] == '.' ||
		command[num].argv[0][0] == '/')
			status = exec_path_program_pipe(command[num].argv[0],
							command[num].argv, all->envp);
		else
			status = exec_envp_path_program_pipe(all, &(command[num]));
		exit(status);
	}
}

int			adaptor_exec_helper(t_shell *command, t_execv *all,
			int *pipefd, int size)
{
	int i;
	int status;
	int exit_code;

	close_all_pipes(pipefd, all->count_pipe);
	close_reds(command, size);
	i = 0;
	exit_code = 0;
	while (i < size)
	{
		wait(&status);
		get_exit_status_pipe(&status);
		if (status != 141)
			exit_code = status;
		i++;
	}
	return (exit_code);
}

int			adaptor_to_exec_pipe(t_execv *all, t_shell *command, int size)
{
	int i;
	int *pipefd;
	int status;

	i = 0;
	pipefd = (int *)malloc(sizeof(int) * (size * 2));
	all->count_pipe = size - 1;
	while (i < size - 1)
	{
		if (pipe(pipefd + i * 2))
			return (error_fork());
		i++;
	}
	i = 0;
	while (i < size)
	{
		exec_command_pipe(all, command, i, pipefd);
		i++;
	}
	status = adaptor_exec_helper(command, all, pipefd, size);
	free(pipefd);
	signal_init();
	return (status);
}
