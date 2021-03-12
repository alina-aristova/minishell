/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:01:37 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/13 00:01:39 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_for_null(char *str)
{
	if (str == NULL)
		exit_malloc();
}

static void	alloc_empty_str_null(char **str)
{
	if (*str == NULL)
		*str = ft_strdup("");
	check_for_null(*str);
}

void		export_work_envp(char **argv, int i, char ***envp)
{
	int		j;
	char	*buf;
	char	*buf_2;

	j = 0;
	while (argv[i][j] != '\0' && argv[i][j] != '=' &&
		!(argv[i][j] == '+' && argv[i][j + 1] == '='))
		j++;
	if (argv[i][j] == '\0' || argv[i][j] == '=')
	{
		buf = ft_strdup(argv[i]);
		check_for_null(buf);
		update_pair(buf, envp);
	}
	else if (argv[i][j] == '+')
	{
		argv[i][j] = '\0';
		buf = env_finder_value(argv[i], *envp);
		alloc_empty_str_null(&buf);
		buf_2 = ft_strjoin(buf, &(argv[i][j + 2]));
		free(buf);
		buf = join_3_str(argv[i], "=", buf_2);
		update_pair(buf, envp);
		free(buf_2);
	}
}

void		print_error_export(const char *str)
{
	int i;

	i = 0;
	ft_putstr_fd("minishell: export: \'", 2);
	while (str[i] != '\0' && str[i] != '=')
	{
		ft_putchar_fd(str[i], 2);
		i++;
	}
	if (str[i] == '=')
		ft_putchar_fd('=', 2);
	ft_putendl_fd("\': not a valid identifier", 2);
}
