/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:21:40 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:21:41 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libftprintfgnl/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_tok
{
	struct s_tok	*next;
	int				type;
	int				pos;
	char			*content;
}					t_tok;

typedef struct	s_cmd
{
	char *cmd;
	char **cmd_args;
	int *fd;
	struct s_cmd    *next;
}	t_cmd;

typedef struct s_shell
{
	char			*read;
	t_cmd 			*cmd;
	t_tok 			*tok;
}	t_shell;
//////////////////////////////MAIN.C////////////////////////////////////////////


//////////////////////////////UTILS_LST.C///////////////////////////////////////
void	lst_show(t_cmd *lst);
t_cmd	*lst_create(char *str);
void	lst_add_back(t_cmd **lst, t_cmd *new);
void	lst_add_front(t_cmd **lst, t_cmd*new);
int		lst_len(t_cmd *lst);
//////////////////////////////UTILS_LST2.C//////////////////////////////////////
void	free_lst(t_shell *shell);

#endif