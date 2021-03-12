/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 03:49:05 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:09:49 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		pipe_red_helper_out(t_shell *command, int num,
								int *pipefd)
{
	if (command[num].output != 1)
	{
		if (dup2(command[num].output, 1) < 0)
			dup2_fail();
		close(pipefd[num * 2 + 1]);
	}
	else
	{
		if (dup2(pipefd[num * 2 + 1], 1) < 0)
			dup2_fail();
	}
}

void		pipe_red_helper_in(t_shell *command, int num,
									int *pipefd)
{
	if (command[num].input != 0)
	{
		if (dup2(command[num].input, 0) < 0)
			dup2_fail();
		close(pipefd[(num - 1) * 2]);
	}
	else
	{
		if (dup2(pipefd[(num - 1) * 2], 0))
			dup2_fail();
	}
}

void		pipe_red_solver(t_shell *command, int num,
				int *pipefd, int size)
{
	if (num == 0)
	{
		if (command[num].input != 0)
			if (dup2(command[num].input, 0) < 0)
				dup2_fail();
		pipe_red_helper_out(command, num, pipefd);
	}
	else if (num == size - 1)
	{
		pipe_red_helper_in(command, num, pipefd);
		if (command[num].output != 1)
			if (dup2(command[num].output, 1) < 0)
				dup2_fail();
	}
	else
	{
		pipe_red_helper_out(command, num, pipefd);
		pipe_red_helper_in(command, num, pipefd);
	}
}

void		close_reds(t_shell *command, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (command[i].input != 0)
			close(command[i].input);
		if (command[i].output != 1)
			close(command[i].output);
		i++;
	}
}

void		close_all_pipes(int *pipefd, int pipe_count)
{
	int i;

	i = 0;
	while (i < 2 * pipe_count)
		close(pipefd[i++]);
}
