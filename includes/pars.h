/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:41:11 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/16 18:05:07 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

# include "libft.h"

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct	s_shell
{

	char	**argv;
	int		output;
	int		input;
}				t_shell;

typedef struct	s_flgs
{
	int flg_two;
	int *len_right_r;
	int *en_left_r;
	int count_sem;
	int *count_pipe;
	int flg_one;
}				t_flgs;

typedef struct	s_all
{
	t_shell	*shell;
	t_flgs	flgs;
	char	**str_pipe;
	int		size_arr;
	char	**res_fill;
	int		exit_code;
}				t_all;

char			**update_split(char const *s, char c);
char			**cat_string(char *str);
void			delete_quotes(char **argv);
void			delete_quotes_str(char *str);
int				check_quotes(const char *str1, t_flgs *flg);
int				check_reds(const char *str1);
int				open_redirection_l(t_shell *shell, char **str, int i);
int				open_redirection_r(t_shell *shell, char **str, int i);
int				is_redirectoin(char *str);
void			init_shell_structs(t_shell *shell, int size);
int				is_empty(char *str);
int				redirection(t_shell *shell, char **str);
int				count_red(char **str);
int				sh_putstr_fd(char *s, int fd);
char			*ft_make_new_substr(char const *start, char const *end);

#endif
