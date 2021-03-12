/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:36:09 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:11:06 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_fd(t_shell *command)
{
	if (command->input != 0)
		if (dup2(command->input, 0) == -1)
			dup2_fail();
	if (command->output != 1)
		if (dup2(command->output, 1) == -1)
			dup2_fail();
}

void	return_input_output(t_execv *all, t_shell *command)
{
	if (command->input != 0)
	{
		close(command->input);
		close(0);
		if (dup2(all->stdin_back, 0) == -1)
			dup2_fail();
	}
	if (command->output != 1)
	{
		close(command->output);
		close(1);
		if (dup2(all->stdout_back, 1) == -1)
			dup2_fail();
	}
}
