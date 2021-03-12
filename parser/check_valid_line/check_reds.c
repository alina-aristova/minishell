/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:58:53 by acase             #+#    #+#             */
/*   Updated: 2021/02/16 20:13:25 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "pars.h"

static void		skipwhitespace(char **str)
{
	while (**str == ' ' || **str == '\n' || **str == '\t' || **str == '\v'
	|| **str == '\f' || **str == '\r')
		(*str)++;
}

char			*skip_char_between_quotes(char *str, char c)
{
	while (*str != c)
		str++;
	if (*str == c)
		str++;
	return (str);
}

int				error_pipe_add_semicolon(char *str)
{
	skipwhitespace(&str);
	if (*str == ';' && *(str + 1) == ';')
		return (sh_putstr_fd("minishell: syntax error near unexpected"
				" token ';;'\n", 2));
	else if (*str == ';')
		return (sh_putstr_fd("minishell: syntax error near unexpected token"
				" ';'\n", 2));
	else if (*str == '|')
	{
		return (sh_putstr_fd("minishell: syntax error near unexpected"
				" token '|'\n", 2));
	}
	return (1);
}

int				error_redirection(char *str)
{
	if (*(str - 1) == '>' && *str == '>')
		str++;
	skipwhitespace(&str);
	if (*str == '<')
		return (sh_putstr_fd("minishell: syntax error near unexpected"
				" token '<'\n", 2));
	else if (*str == '>' && *(str + 1) == '>')
		return (sh_putstr_fd("minishell: syntax error near unexpected"
				" token '>>'\n", 2));
	else if (*str == '>')
		return (sh_putstr_fd("minishell: syntax error near unexpected"
				" token '>'\n", 2));
	else if (*str == '\0')
		return (sh_putstr_fd("minishell: syntax error near unexpected"
				" token 'newline'\n", 2));
	else
		return (error_pipe_add_semicolon(str));
	return (1);
}

int				check_reds(const char *str1)
{
	char *str;

	str = (char*)str1;
	if (!error_pipe_add_semicolon(str))
		return (0);
	while (*str != '\0')
	{
		if (*str == '\'' || *str == '\"')
			str = skip_char_between_quotes(str + 1, *str);
		if (*str == '|' || *str == ';')
			return (error_pipe_add_semicolon(str + 1));
		else if (*str == '>' || *str == '<')
			return (error_redirection(str + 1));
		str++;
	}
	return (1);
}
