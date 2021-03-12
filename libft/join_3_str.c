/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_3_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:52:23 by bhankey           #+#    #+#             */
/*   Updated: 2021/01/20 20:16:47 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*join_3_str(char *str1, char *str2, char *str3)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + strlen(str3) + 1;
	res = malloc(len);
	if (res == NULL)
		return (NULL);
	len = 0;
	while (str1[len] != '\0')
		res[i++] = str1[len++];
	len = 0;
	while (str2[len] != '\0')
		res[i++] = str2[len++];
	len = 0;
	while (str3[len] != '\0')
		res[i++] = str3[len++];
	res[i] = '\0';
	return (res);
}
