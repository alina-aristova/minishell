/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_structer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:40:56 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/04 20:40:59 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ALL_STRUCTER_H
# define MINISHELL_ALL_STRUCTER_H

typedef struct		s_execv {
	int		stdin_back;
	int		stdout_back;
	t_shell **shell;
	char	**envp;
	int		exit_status;
	int		count_pipe;
}					t_execv;

#endif
