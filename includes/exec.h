/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:41:01 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:10:41 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H

# include "all_structer.h"
# include "pars.h"

int			call_build_in(t_execv *all, t_shell *command, int func, int pipe);
int			is_build_in(char *str);
int			exec_command_single(t_execv *all, t_shell *command, int pipe);
void		make_fd(t_shell *command);
void		return_input_output(t_execv *all, t_shell *command);
void		make_new_string_set_err(char **buf, char *name, int *err);
void		get_exit_status(int *status);
int			execute_pipe_build_in(t_execv *execv, t_shell *comm, int pipe,
									int status);

#endif
