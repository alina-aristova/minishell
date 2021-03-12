/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:51:30 by acase             #+#    #+#             */
/*   Updated: 2021/02/16 18:53:28 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

static void		singl_quote(t_flgs *flg)
{
	if (flg->flg_one == 0)
	{
		if (flg->flg_two == 0)
			flg->flg_one = 1;
		else
			return ;
	}
	else
		flg->flg_one = 0;
}

static void		double_quote(t_flgs *flg)
{
	if (flg->flg_two == 0)
	{
		if (flg->flg_one == 0)
			flg->flg_two = 1;
		else
			return ;
	}
	else
		flg->flg_two = 0;
}

int				check_quotes(const char *str1, t_flgs *flg)
{
	char *str;

	flg->flg_two = 0;
	flg->flg_one = 0;
	str = (char*)str1;
	while (*str)
	{
		if (!ft_memcmp(str, "\'", 1) || !ft_memcmp(str, "\"", 1))
			!ft_memcmp(str, "\'", 1) ? singl_quote(flg) :
				double_quote(flg);
		str++;
	}
	return ((flg->flg_two == 1 || flg->flg_one == 1) ? FALSE : TRUE);
}
