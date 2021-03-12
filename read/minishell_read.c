/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:06:06 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/10 21:34:08 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reallocate_string(char **str, int *buffer_size)
{
	char *buf;
	char *to_del;

	buf = calloc(*buffer_size * 2, sizeof(char));
	if (buf == NULL)
		exit_malloc();
	ft_strlcpy(buf, *str, *buffer_size);
	*buffer_size *= 2;
	to_del = *str;
	*str = buf;
	free(to_del);
}

void	init_gnl_shell(int *buffer_size, int *pos, int *pipe, char **line)
{
	*buffer_size = 512;
	*line = ft_calloc(*buffer_size, sizeof(char));
	*pos = 0;
	*pipe = 0;
	if (*line == NULL)
		exit_malloc();
}

int		gnl_shell(char **line, int exit_code)
{
	int		buffer_size;
	char	c;
	int		flag;
	int		pos;
	int		pipe;

	init_gnl_shell(&buffer_size, &pos, &pipe, line);
	while ((flag = read(0, &c, 1)) >= 0)
	{
		eof_read_case(flag, exit_code, line);
		if (c == '\n')
			break ;
		if (flag == 0)
			continue ;
		if (pos + 1 >= buffer_size)
			reallocate_string(line, &buffer_size);
		(*line)[pos++] = c;
		if (pipe == 0 && c == '|')
			pipe = 1;
		else if (pipe == 1 && c != ' ')
			pipe = 0;
	}
	return (pipe);
}

void	gnl_pipe(char **line, int *pipe, int exit_code)
{
	int		buffer_size;
	char	c;
	int		flag;
	int		pos;

	buffer_size = 512;
	*line = ft_calloc(buffer_size, sizeof(char));
	pos = 0;
	if (*line == NULL)
		exit_malloc();
	while ((flag = read(0, &c, 1)) >= 0)
	{
		eof_read_case(flag, exit_code, line);
		if (c == '\n')
			break ;
		if (pos + 1 >= buffer_size)
			reallocate_string(line, &buffer_size);
		(*line)[pos++] = c;
		if (*pipe == 0 && c == '|')
			*pipe = 1;
		else if (*pipe == 1 && c != ' ')
			*pipe = 0;
	}
}

void	shell_read(char **line, int exit_code)
{
	int		pipe;
	char	*next_line;
	char	*buf;

	pipe = gnl_shell(line, exit_code);
	while (pipe == 1)
	{
		ft_putchar_fd('>', 1);
		ft_putchar_fd(' ', 1);
		gnl_pipe(&next_line, &pipe, exit_code);
		buf = ft_strjoin(*line, next_line);
		free(*line);
		free(next_line);
		*line = buf;
	}
}
