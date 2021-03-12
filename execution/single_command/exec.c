/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:49:08 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/13 15:50:04 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_path_program(char *name, char **argv, char **envp)
{
	int		status;
	pid_t	pid;

	status = 1;
	signal(SIGINT, signal_proc);
	signal(SIGQUIT, signal_quit_fork);
	pid = fork();
	if (pid == -1)
		exit_fork();
	else if (pid == 0)
	{
		execve(name, argv, envp);
		print_error(name);
		if (errno == 13)
			exit(126);
		if (errno == 2)
			exit(127);
		exit(errno);
	}
	else if (pid > 0)
		wait(&status);
	signal_init();
	return (status);
}

static int	exec_path_help_helper(char **envp, char **argv, char **path)
{
	int		pid;
	int		i;
	char	*buf;
	char	*name;

	i = 0;
	pid = 2;
	buf = ft_strdup(argv[0]);
	while (path[i] != NULL)
	{
		name = join_3_str(path[i], "/", argv[0]);
		execve(name, argv, envp);
		if (errno != 2)
			make_new_string_set_err(&buf, name, &pid);
		i++;
		free(name);
	}
	errno = pid;
	print_error_fork(buf);
	if (errno == 13)
		exit(126);
	if (errno == 2)
		exit(127);
	exit(errno);
}

static int	exec_path_helper(char **path, char **argv, char **envp)
{
	pid_t	pid;
	int		status;

	signal(SIGINT, signal_proc);
	signal(SIGQUIT, signal_quit_fork);
	pid = fork();
	status = 1;
	if (pid == -1)
		exit_fork();
	else if (pid == 0)
		exec_path_help_helper(envp, argv, path);
	else if (pid > 0)
		wait(&status);
	signal_init();
	return (status);
}

static int	exec_envp_path_program(t_execv *all, t_shell *command)
{
	int		status;
	char	**path;
	char	*env_path;

	env_path = env_finder_value("PATH", all->envp);
	if (env_path == NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(command->argv[0], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (127);
	}
	path = ft_split(env_path, ':');
	status = exec_path_helper(path, command->argv, all->envp);
	clear_2d_arr(path);
	free(env_path);
	return (status);
}

int			exec_command_single(t_execv *all, t_shell *command, int pipe)
{
	int status;

	if (command->argv[0][0] == '\0')
	{
		ft_putendl_fd("minishell: : command not found", 2);
		return (127);
	}
	make_fd(command);
	if ((status = is_build_in(command->argv[0])) && pipe == 0)
		status = call_build_in(all, command, status, 0);
	else if (status)
		status = execute_pipe_build_in(all, command, pipe, status);
	else if (command->argv[0][0] == '.' || command->argv[0][0] == '/')
		status = exec_path_program(command->argv[0], command->argv, all->envp);
	else
		status = exec_envp_path_program(all, command);
	return_input_output(all, command);
	if (pipe || !is_build_in(command->argv[0]))
		get_exit_status(&status);
	else
		status = (unsigned char)status;
	return (status);
}
