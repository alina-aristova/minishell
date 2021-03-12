/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:51:53 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/19 20:51:54 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_in_functions.h"
#include <unistd.h>
#include "errno.h"

int	pwd(void)
{
	char *buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
	{
		ft_putstr_fd("pwd: error retrieving current directory: getcwd:"
			"cannot access parent directories: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	ft_putendl_fd(buf, 1);
	free(buf);
	return (0);
}
