/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:51:35 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/19 20:51:38 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	echo(int argc, char **argv)
{
	int i;
	int flag;

	i = 0;
	if (argc > 0)
	{
		flag = ft_strncmp(argv[0], "-n", 10);
		i = flag != 0 ? 0 : 1;
		if (argc > 1)
			while (argv[i] != NULL && !ft_strncmp(argv[i], "-n", 10))
				i++;
	}
	while (i < argc)
	{
		ft_putstr_fd(argv[i++], 1);
		if (i < argc)
			ft_putstr_fd(" ", 1);
	}
	if (flag != 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
