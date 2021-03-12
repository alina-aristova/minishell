/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:19:26 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 15:19:28 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_path_program_pipe(char *name, char **argv, char **envp)
{
	signal(SIGINT, signal_proc);
	signal(SIGQUIT, signal_quit_fork);
	execve(name, argv, envp);
	print_error(name);
	if (errno == 13)
		exit(126);
	if (errno == 2)
		exit(127);
	exit(errno);
}

static int	exec_path_help_helper_pipe(char **envp, char **argv, char **path)
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

static int	exec_path_helper_pipe(char **path, char **argv, char **envp)
{
	signal(SIGINT, signal_proc);
	signal(SIGQUIT, signal_quit_fork);
	exec_path_help_helper_pipe(envp, argv, path);
	return (0);
}

int			exec_envp_path_program_pipe(t_execv *all, t_shell *command)
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
		exit(127);
	}
	path = ft_split(env_path, ':');
	status = exec_path_helper_pipe(path, command->argv, all->envp);
	clear_2d_arr(path);
	free(env_path);
	exit(status);
}
