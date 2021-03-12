/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_read_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:12:15 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/13 00:12:17 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	eof_read_case(int flag, int exit_code, char **line)
{
	if (flag == 0 && **line == '\0')
		exit_build_in(0, NULL, 0, exit_code);
	if (flag == 0)
		ft_putstr_fd("  \b\b", 2);
}
