/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:07:17 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:07:18 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		append_pair(char *pair, char ***envp)
{
	char	**env_buf;
	int		size;
	int		i;

	size = size_of_2d_array(*envp) + 1;
	env_buf = malloc((size + 2) * sizeof(char *));
	if (env_buf == NULL)
		exit_malloc();
	i = 0;
	while ((*envp)[i] != NULL)
	{
		env_buf[i] = (*envp)[i];
		i++;
	}
	env_buf[i++] = pair;
	env_buf[i] = NULL;
	free(*envp);
	*envp = env_buf;
}

void			update_pair(char *pair, char ***envp)
{
	int i;

	i = env_finder_i(pair, *envp);
	if (i == -1)
	{
		append_pair(pair, envp);
		return ;
	}
	free((*envp)[i]);
	(*envp)[i] = pair;
}

void			update_value(char *key, char *new_value, char ***envp)
{
	int		i;
	char	*pair;

	i = env_finder_i(key, *envp);
	if (i == -1)
	{
		pair = join_3_str(key, "=", new_value);
		if (pair == NULL)
			exit_malloc();
		append_pair(pair, envp);
		return ;
	}
	pair = join_3_str(key, "=", new_value);
	free((*envp)[i]);
	(*envp)[i] = pair;
}

void			delete_value(char *key, char **envp)
{
	int i;

	i = env_finder_i(key, envp);
	if (i == -1)
		return ;
	free(envp[i]);
	while (envp[i + 1] != NULL)
	{
		envp[i] = envp[i + 1];
		i++;
	}
	envp[i] = NULL;
}
