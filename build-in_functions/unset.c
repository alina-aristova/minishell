/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:51:57 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/19 20:51:58 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_identifier(char *str)
{
	int i;

	i = 0;
	if (!(str[i] == '_' || ft_isalpha(str[i]) == 1))
		return (1);
	i++;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int			unset(int argc, char **argv, char **envp)
{
	int i;
	int status;

	i = 0;
	status = 0;
	while (i < argc)
	{
		if (check_identifier(argv[i]) == 1)
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': not a valid identifier", 2);
			status = 1;
		}
		else
			delete_value(argv[i], envp);
		i++;
	}
	return (status);
}
