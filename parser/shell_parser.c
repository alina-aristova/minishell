/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:15:31 by acase             #+#    #+#             */
/*   Updated: 2021/02/16 14:58:36 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parser(char *line, t_all *all, t_execv *exec, int exit_code)
{
	char	**s;
	int		i;

	i = 0;
	if (check_quotes(line, &all->flgs))
	{
		if (!check_reds(line))
			return (258);
	}
	else
	{
		ft_putendl_fd("minishell: quotes wasn't close", 2);
		return (258);
	}
	s = update_split(line, ';');
	while (s[i])
	{
		s[i] = put_var(s[i], exec->envp, exit_code);
		exec->exit_status = exit_code;
		exit_code = get_args(all, s[i], exec);
		i++;
	}
	clear_2d_arr(s);
	return (exit_code);
}
