/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:56:08 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/15 14:23:22 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_str_left(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[j] != '\0')
		str[i++] = str[j++];
	str[i] = '\0';
}

void	delete_quotes_str(char *str)
{
	int		status;
	int		i;
	char	buf;

	i = 0;
	status = 0;
	while (str[i] != '\0')
	{
		buf = str[i];
		if (status == 0 && (str[i] == '\"' || str[i] == '\''))
			move_str_left(&(str[i]));
		else if (status == 1 && (str[i] == '\"'))
			move_str_left(&(str[i]));
		else if (status == 2 && (str[i] == '\''))
			move_str_left(&(str[i]));
		else
			i++;
		change_status(buf, &status);
	}
}

void	delete_quotes(char **argv)
{
	int word;

	word = 0;
	while (argv[word] != NULL)
	{
		delete_quotes_str(argv[word]);
		word++;
	}
}
