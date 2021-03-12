/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:06:22 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/18 21:06:24 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	clear_2d_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}
