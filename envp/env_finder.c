/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:07:13 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:07:14 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static char		*get_value(char *env, const char *key)
{
	int i;

	i = 0;
	while (env[i] != '\0' && env[i] != '=')
	{
		if ((env[i] != key[i]) && (env[i]))
			return (NULL);
		i++;
	}
	if ((env[i] == '=' && (key[i] == '\0' || key[i] == '=')) ||
	(key[i] == '=' && (env[i] == '\0' || env[i] == '=')))
		return (&(env[i + 1]));
	return (NULL);
}

/*
 ** return address of value, need to be freed!!!
*/

char			*env_finder_value(char *key, char **env)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (env[i] != NULL)
	{
		if ((value = get_value(env[i], key)) != NULL)
		{
			value = ft_strdup(value);
			break ;
		}
		i++;
	}
	return (value);
}

/*
 ** return position in array
*/

int				env_finder_i(char *key, char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (get_value(env[i], key) != NULL)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
