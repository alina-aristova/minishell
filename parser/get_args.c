/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:56:14 by acase             #+#    #+#             */
/*   Updated: 2021/02/16 20:09:15 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_norm(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	**fill_struct(t_shell *shell, char *str)
{
	char	**str_ar;
	int		i;
	int		j;
	int		count;

	fill_norm(&i, &j);
	str_ar = cat_string(str);
	count = size_of_2d_array(str_ar) - 2 * count_red(str_ar);
	shell->argv = malloc((count + 1) * sizeof(char *));
	while (str_ar[i])
	{
		if (i != 0 && (is_redirectoin(str_ar[i - 1])))
			delete_quotes_str(str_ar[i]);
		if (i == 0)
		{
			if ((!is_redirectoin(str_ar[i])))
				shell->argv[j++] = ft_strdup(str_ar[i]);
		}
		else if (!is_redirectoin(str_ar[i]) && !is_redirectoin(str_ar[i - 1]))
			shell->argv[j++] = ft_strdup(str_ar[i]);
		i++;
	}
	shell->argv[j] = NULL;
	delete_quotes(shell->argv);
	return (str_ar);
}

void	exec_helper_norm(t_all *all, t_execv *execv)
{
	if (all->size_arr == 1)
		all->exit_code = (exec_command_single(execv, &all->shell[0],
											all->size_arr - 1));
	else
		all->exit_code = (adaptor_to_exec_pipe(execv, all->shell,
											all->size_arr));
}

void	get_args_clear_mem(t_all *all)
{
	int i;

	i = 0;
	while (i < all->size_arr)
		clear_2d_arr(all->shell[i++].argv);
	clear_2d_arr(all->str_pipe);
	clear_2d_arr(all->res_fill);
	free(all->shell);
}

int		get_args(t_all *all, char *str, t_execv *execv)
{
	int	i;

	i = 0;
	if (is_empty(str))
		return (0);
	all->str_pipe = update_split(str, '|');
	all->size_arr = size_of_2d_array(all->str_pipe);
	if (!(all->shell = malloc((all->size_arr) * sizeof(t_shell))))
		exit_malloc();
	init_shell_structs(all->shell, all->size_arr);
	while (i < all->size_arr)
	{
		all->res_fill = fill_struct(&(all->shell[i]), all->str_pipe[i]);
		if (redirection(&(all->shell[i]), all->res_fill) == 1)
			return (1);
		i++;
	}
	exec_helper_norm(all, execv);
	get_args_clear_mem(all);
	return (all->exit_code);
}
