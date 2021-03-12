/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:07:26 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:08:14 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	exit_malloc(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	exit_fork(void)
{
	ft_putendl_fd("can not create fork", 2);
	exit(1);
}

int		error_fork(void)
{
	ft_putstr_fd("minishell: fork: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}
