/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:58:03 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/04 17:58:06 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	dup_fail(void)
{
	ft_putendl_fd("dup failed to back up stdin or stdout", 2);
	exit(1);
}

void	dup2_fail(void)
{
	ft_putendl_fd("dup2 failed", 2);
	exit(1);
}
