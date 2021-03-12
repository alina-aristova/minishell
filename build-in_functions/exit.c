/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:46:36 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/04 17:46:39 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_num(char *str)
{
	int					i;
	int					size;
	unsigned long long	num;

	i = 0;
	size = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = ft_atoi_ull(&(str[i]));
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
		size++;
	}
	if (size > 19)
		return (0);
	if ((num > 9223372036854775808ull && str[0] == '-') ||
		(num > 9223372036854775807 && str[0] != '-'))
	{
		return (0);
	}
	return (1);
}

static int		print_error_dont_exit(void)
{
	ft_putendl_fd("minishell: exit: too many arguments", 2);
	return (1);
}

static int		exit_with_2_error(char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": numeric argument required", 2);
	exit(255);
}

static int		exit_one_num_case(char **argv)
{
	int					i;
	int					sign;
	unsigned long long	num;

	sign = 1;
	i = 0;
	if (argv[0][i] == '-' || argv[0][i] == '+')
	{
		if (argv[0][i] == '-')
			sign = -1;
		i++;
	}
	num = ft_atoi_ull(&(argv[0][i]));
	if ((num > 9223372036854775808ull && sign == -1) ||
		(num > 9223372036854775807 && sign == 1))
	{
		exit_with_2_error(argv[0]);
		exit(255);
	}
	else
		exit((unsigned char)((long long int)num * sign));
}

int				exit_build_in(int argc, char **argv, int pipe, int exit_code)
{
	if (pipe == 0)
		ft_putendl_fd("exit", 2);
	if (argc == 0)
		exit((unsigned char)exit_code);
	if (argc == 1 && is_num(argv[0]))
		return (exit_one_num_case(argv));
	else if (is_num(argv[0]))
		return (print_error_dont_exit());
	else
		return (exit_with_2_error(argv[0]));
}
