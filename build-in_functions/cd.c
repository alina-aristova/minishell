/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:07:07 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:07:09 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	path_not_exist(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(" ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

static int	cd_to_home(char ***envp, char *pwd)
{
	char	*home;
	int		status;

	home = env_finder_value("HOME", *envp);
	if (home == NULL)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (1);
	}
	if ((status = chdir(home)) == -1)
	{
		path_not_exist(home);
		free(home);
		return (1);
	}
	if (pwd != NULL)
		update_value("OLDPWD", pwd, envp);
	if (status < 0)
		status *= -1;
	free(home);
	return (status);
}

static int	cd_to_path(char ***envp, char *path, char *pwd)
{
	char	*path_pwd;
	int		status;

	if ((status = chdir(path)) == -1)
	{
		path_not_exist(path);
		return (1);
	}
	path_pwd = getcwd(NULL, 0);
	if (path_pwd != NULL)
		update_value("PWD", path_pwd, envp);
	if (pwd != NULL)
		update_value("OLDPWD", pwd, envp);
	free(path_pwd);
	if (status < 0)
		status *= -1;
	return (status);
}

int			cd(int argc, char **argv, char ***envp)
{
	char	*pwd;
	int		status;

	if (argc > 1)
	{
		ft_putstr_fd("minishell: cd: too many arguments ", 2);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd:"
			"cannot access parent directories: ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	if (argc == 0)
		status = cd_to_home(envp, pwd);
	else
		status = cd_to_path(envp, argv[0], pwd);
	free(pwd);
	return (status);
}
