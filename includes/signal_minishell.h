/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_minishell.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:55:50 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/10 14:55:54 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNAL_MINISHELL_H
# define MINISHELL_SIGNAL_MINISHELL_H

# include <signal.h>

void	signal_init();
void	signal_quit(int signal);
void	signal_int(int signal);
void	signal_proc(int signal);
void	signal_quit_fork(int signal);

#endif
