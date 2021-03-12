/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocate_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:07:21 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:07:22 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**reallocate_envp(char **envp)
{
	char	**env;
	int		i;

	i = 0;
	env = (char **)malloc((size_of_2d_array(envp) + 1) * sizeof(char *));
	if (env == NULL)
		exit_malloc();
	while (envp[i] != NULL)
	{
		env[i] = ft_strdup(envp[i]);
		if (env[i] == NULL)
			exit_malloc();
		i++;
	}
	env[i] = NULL;
	return (env);
}
