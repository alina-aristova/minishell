/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:51:02 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/09 03:51:04 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		make_new_string_set_err(char **buf, char *name, int *err)
{
	free(*buf);
	*buf = ft_strdup(name);
	*err = errno;
}

void		get_exit_status(int *status)
{
	if (WIFEXITED(*status))
		*status = (WEXITSTATUS(*status));
	else if (WIFSIGNALED(*status))
	{
		*status = WTERMSIG(*status) + 128;
		if (*status == 130)
			ft_putendl_fd("", 1);
	}
}

int			execute_pipe_build_in(t_execv *execv, t_shell *comm, int pipe,
						int status)
{
	t_execv		execv1;

	execv1 = *execv;
	execv1.envp = reallocate_envp(execv->envp);
	status = call_build_in(&execv1, comm, status, pipe);
	clear_2d_arr(execv1.envp);
	exit(status);
}
