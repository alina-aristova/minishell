/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:57:20 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/04 17:57:23 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		change_status(char ch, int *status)
{
	if (ch == '\"' && *status == 0)
		*status = 1;
	else if (ch == '\'' && *status == 0)
		*status = 2;
	else if ((ch == '"' && *status == 1) || (ch == '\'' && *status == 2))
		*status = 0;
}

static void	put_exit_code(char **str, int exit_code, int i)
{
	char	*buf;
	char	*buf_2;

	(*str)[i] = '\0';
	buf = ft_itoa(exit_code);
	buf_2 = join_3_str(*str, buf, &((*str)[i + 2]));
	free(*str);
	free(buf);
	*str = buf_2;
}

static void	delete_some_chars(char **str, int i, int transition)
{
	char	*buf;

	(*str)[i] = '\0';
	buf = ft_strjoin(*str, &((*str)[i + transition]));
	free(*str);
	*str = buf;
}

static void	put_envp_var(char **str, int i, char **envp)
{
	int		stop;
	char	*buf;
	char	*buf_2;

	stop = i + 1;
	while (ft_isalnum((*str)[stop]) || (*str)[stop] == '_')
		stop++;
	buf = malloc((stop - i) * sizeof(char));
	ft_strlcpy(buf, &((*str)[i + 1]), stop - i);
	(*str)[i] = '\0';
	buf_2 = env_finder_value(buf, envp);
	if (buf_2 == NULL)
		buf_2 = strdup("");
	free(buf);
	buf = join_3_str(*str, buf_2, &((*str)[stop]));
	free(buf_2);
	free(*str);
	*str = buf;
}

char		*put_var(char *str, char **envp, int exit_code)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (str[i] != '\0')
	{
		change_status(str[i], &status);
		if (str[i] == '$' && status != 2)
		{
			if (str[i + 1] == '?')
				put_exit_code(&str, exit_code, i);
			else if (ft_isdigit(str[i + 1]))
				delete_some_chars(&str, i, 2);
			else if (status == 0 && (str[i + 1] == '"' || str[i + 1] == '\''))
				delete_some_chars(&str, i, 1);
			else if (ft_isalpha(str[i + 1]) || str[i + 1] == '_')
				put_envp_var(&str, i, envp);
			else
				i++;
		}
		else
			i++;
	}
	return (str);
}
