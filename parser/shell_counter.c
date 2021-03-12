/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:37:57 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:06:41 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		skip_white_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void			shell_count_strs_norm(char *str, int *i, int *count,
							int to_plus)
{
	(*count)++;
	*i += to_plus;
	if (str[*i] != ' ' && str[*i] != '\t')
		(*count)++;
}

int				shell_count_strs(char *str)
{
	int i;
	int count;
	int status;

	count = 0;
	status = 0;
	i = 0;
	skip_white_spaces(str, &i);
	while (str[i] != '\0')
	{
		change_status(str[i], &status);
		if (str[i] == ' ' && status == 0)
		{
			count++;
			skip_white_spaces(str, &i);
		}
		else if (((str[i] == '>' && str[i + 1] != '>') || (str[i] == '<'))
				&& status == 0)
			shell_count_strs_norm(str, &i, &count, 1);
		else if (str[i] == '>' && str[i + 1] == '>' && status == 0)
			shell_count_strs_norm(str, &i, &count, 2);
		else
			i++;
	}
	return (count + 2);
}
