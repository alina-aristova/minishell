/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build-in_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:08:17 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:08:18 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILD_IN_FUNCTIONS_H
# define MINISHELL_BUILD_IN_FUNCTIONS_H

# include <stdlib.h>
# include "libft.h"

int		check_identifier(char *str);
int		echo(int argc, char **argv);
int		pwd();
int		unset(int argc, char **argv, char **envp);
int		env(char **envp);
int		export(int argc, char **argv, char ***envp);
int		cd(int argc, char **argv, char ***envp);
int		exit_build_in(int argc, char **argv, int pipe, int exit_code);
void	export_work_envp(char **argv, int i, char ***envp);
void	print_error_export(const char *str);

#endif
