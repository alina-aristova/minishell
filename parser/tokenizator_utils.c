/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizator_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:39:14 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:05:26 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_white_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void		redir_left_rigth_norm_helper(char **strs, int i,
			int *word, char *str)
{
	if (i == 0)
	{
		strs[*word] = malloc(2 * sizeof(char));
		ft_strlcpy(strs[(*word)++], str, 2);
	}
	else
	{
		strs[*word + 1] = malloc(2 * sizeof(char));
		ft_strlcpy(strs[*word + 1], &(str[i]), 2);
		str[i] = '\0';
		strs[*word] = ft_strdup(str);
		*word += 2;
	}
}

void		redir_right_right_norm_helper(char **strs, int i,
			int *word, char *str)
{
	if (i == 0)
	{
		strs[*word] = malloc(3 * sizeof(char));
		ft_strlcpy(strs[(*word)++], str, 3);
	}
	else
	{
		strs[*word + 1] = malloc(3 * sizeof(char));
		ft_strlcpy(strs[*word + 1], &(str[i]), 3);
		str[i] = '\0';
		strs[*word] = ft_strdup(str);
		*word += 2;
	}
}

void		init_vars_norm(int *i, int *word, int *status)
{
	*word = 0;
	*i = 0;
	*status = 0;
}

void		skip_white_spaces_and_euq(char **str, int *i)
{
	skip_white_spaces(*str, i);
	*str = &((*str)[*i]);
	*i = 0;
}
