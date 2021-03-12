/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:51:46 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/19 20:51:50 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_identifier_export(char *str)
{
	int i;

	i = 0;
	if (!(str[i] == '_' || ft_isalpha(str[i]) == 1))
		return (1);
	i++;
	while (str[i] != '\0' && str[i] != '=' &&
	!(str[i] == '+' && str[i + 1] == '='))
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

static void	print_env(char **env)
{
	int i;
	int j;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=')
			write(1, &(env[i][j++]), 1);
		if (env[i][j] == '\0')
		{
			write(1, "\n", 1);
			i++;
			continue;
		}
		write(1, &(env[i][j++]), 1);
		write(1, "\"", 1);
		while (env[i][j] != '\0')
			write(1, &(env[i][j++]), 1);
		write(1, "\"\n", 2);
		i++;
	}
}

static void	swap(char **env, int j)
{
	char *buf;

	buf = env[j];
	env[j] = env[j + 1];
	env[j + 1] = buf;
}

static int	sort_and_print(char **envp)
{
	char	**env_b;
	int		i;
	int		j;

	env_b = reallocate_envp(envp);
	if (env_b == NULL)
		exit_malloc();
	i = 0;
	while (i < size_of_2d_array(env_b))
	{
		j = 0;
		while (j < size_of_2d_array(env_b) - i - 1)
		{
			if (ft_strncmp(env_b[j], env_b[j + 1], strlen(env_b[j])) > 0)
				swap(env_b, j);
			j++;
		}
		i++;
	}
	print_env(env_b);
	clear_2d_arr(env_b);
	return (0);
}

int			export(int argc, char **argv, char ***envp)
{
	int		i;
	int		status;

	status = 0;
	if (argc == 0)
		return (sort_and_print(*envp));
	i = 0;
	while (i < argc)
	{
		if (check_identifier_export(argv[i]))
		{
			status = 1;
			print_error_export(argv[i]);
		}
		else
			export_work_envp(argv, i, envp);
		i++;
	}
	return (status);
}
