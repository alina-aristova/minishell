/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:08:22 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:08:28 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MINISHELL_H
# define MINISHELL_MINISHELL_H

# include "build_in_functions.h"
# include "exit.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "signal_minishell.h"
# include "pars.h"
# include "all_structer.h"
# include "exec.h"
# include "sys/wait.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1

/*
 ** utils functions
*/

void	change_status(char ch, int *status);
int		execute_commands(t_all *all, t_execv *execv, int size_arr);
int		parser(char *line, t_all *all, t_execv *exec, int exit_code);
void	shell_read(char **line, int exit_code);
void	eof_read_case(int flag, int exit_code, char **line);
int		exec_path_program_pipe(char *name, char **argv, char **envp);
int		exec_envp_path_program_pipe(t_execv *all, t_shell *command);
int		adaptor_to_exec_pipe(t_execv *all, t_shell *command, int size);
void	pipe_red_solver(t_shell *command, int num, int *pipefd, int size);
void	close_reds(t_shell *command, int size);
void	close_all_pipes(int *pipefd, int pipe_count);
int		shell_count_strs(char *str);
void	skip_white_spaces_and_euq(char **str, int *i);
void	init_vars_norm(int *i, int *word, int *status);
void	redir_right_right_norm_helper(char **strs, int i, int *word, char *str);
void	redir_left_rigth_norm_helper(char **strs, int i, int *word, char *str);

/*
 ** signal functions
*/

void	signal_init();

/*
 ** env functions
*/

void	update_pair(char *pair, char ***envp);
void	update_value(char *key, char *new_value, char ***envp);
char	*env_finder_value(char *key, char **env);
int		env_finder_i(char *key, char **env);
void	delete_value(char *key, char **envp);
char	**reallocate_envp(char **envp);

/*
 ** for parser functions
*/

char	*put_var(char *str, char **envp, int exit_code);
int		get_args(t_all *all, char *str, t_execv *execv);

#endif
