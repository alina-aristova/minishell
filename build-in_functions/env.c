/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:51:41 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/19 20:51:43 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_putendl_fd(envp[i], 1);
		i++;
	}
	return (0);
}
