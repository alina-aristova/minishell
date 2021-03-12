/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:55:59 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 20:07:14 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dup_string_space(char **str, int *i, char **strs, int *word)
{
	(*str)[(*i)++] = '\0';
	strs[(*word)++] = ft_strdup(*str);
	skip_white_spaces_and_euq(str, i);
}

void	redir_right_left_dup(char **strs, int *i, int *word, char **str)
{
	redir_left_rigth_norm_helper(strs, *i, word, *str);
	(*i)++;
	skip_white_spaces_and_euq(str, i);
}

void	redir_right_right_dup(char **strs, int *i, int *word, char **str)
{
	redir_right_right_norm_helper(strs, *i, word, *str);
	*i += 2;
	skip_white_spaces_and_euq(str, i);
}

char	**cat_string(char *str)
{
	int		word;
	int		status;
	char	**strs;
	int		i;

	strs = (char**)malloc(sizeof(char *) * (shell_count_strs(str) + 1));
	init_vars_norm(&i, &word, &status);
	skip_white_spaces_and_euq(&str, &i);
	while (str[i] != '\0')
	{
		change_status(str[i], &status);
		if (str[i] == ' ' && status == 0)
			dup_string_space(&str, &i, strs, &word);
		else if (((str[i] == '>' && str[i + 1] != '>') || (str[i] == '<')) &&
		status == 0)
			redir_right_left_dup(strs, &i, &word, &str);
		else if (str[i] == '>' && str[i + 1] == '>' && status == 0)
			redir_right_right_dup(strs, &i, &word, &str);
		else
			i++;
	}
	if (i != 0)
		strs[word++] = ft_strdup(str);
	strs[word] = NULL;
	return (strs);
}
