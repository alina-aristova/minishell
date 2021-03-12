# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acase <acase@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 01:59:37 by bhankey           #+#    #+#              #
#    Updated: 2021/02/13 13:55:07 by acase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c envp/env_finder.c build-in_functions/echo.c build-in_functions/pwd.c \
			exit_error_functions/exit_malloc.c build-in_functions/cd.c envp/reallocate_envp.c \
			envp/env_update.c build-in_functions/unset.c build-in_functions/export.c build-in_functions/env.c \
			build-in_functions/exit.c exit_error_functions/exit_dup.c envp/put_vars.c \
			signal/signal_main.c parser/get_args.c parser/update_split.c \
			exit_error_functions/error_funcs.c parser/tokenizator.c \
			parser/delete_quotes.c read/minishell_read.c build-in_functions/export_utils.c read/minishell_read_utils.c \
			parser/check_valid_line/check_quotes.c parser/check_valid_line/check_reds.c \
			execution/pipe_commands/pipe_exec.c execution/pipe_commands/pipe_commands.c \
			execution/pipe_commands/fd_helper.c  execution/single_command/exec.c execution/single_command/exec_build_in.c \
			execution/single_command/exec_utils.c execution/single_command/make_file_fd.c \
			parser/shell_counter.c parser/tokenizator_utils.c \
			parser/open_redirection.c \
            parser/parser_utils.c parser/put_error.c parser/shell_parser.c

NAME	=	minishell

OBJS	=	$(SRCS:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror  -I ./libft -I ./includes

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) bonus -C libft
			$(CC) $(CFALGS)  $(OBJS) ./libft/libft.a -o minishell

clean:
			rm -f $(OBJS)
			$(MAKE) clean -C libft

fclean:		clean
			$(MAKE) fclean -C libft
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re