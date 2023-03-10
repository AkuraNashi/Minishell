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

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct t_exec
{
	char			**cmd_args;
	struct t_exec	*next;
	struct t_exec	*prev;
}	t_exec;

typedef struct s_shell
{
	char			*read;
	char			**cmd_args;
	int				pipe[2];
	t_cmd			*cmd;
	t_exec			*exec;
}	t_shell;

//////////////////////////////MAIN.C////////////////////////////////////////////
void	parsing(t_shell *shell);
void	init_shell(t_shell *shell);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////Execution///////////////////////////////////////////
//////////////////////////////Folder////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//////////////////////////////EXECUTION.C///////////////////////////////////////
void	execution(void);
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////Utils/////////////////////////////////////////////
//////////////////////////////Folder////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//////////////////////////////UTILS_LST.C///////////////////////////////////////
void	lst_show(t_cmd *lst);
int		lst_len(t_cmd *lst);
void	lst_add_front(t_cmd **lst, t_cmd *new);
void	lst_add_back(t_cmd **lst, t_cmd *new);
t_cmd	*lst_create(char *str);

//////////////////////////////UTILS_LST2.C//////////////////////////////////////
void	printf_list(t_cmd *lst);
void	free_lst(t_shell *shell);
int		len_cmd(t_shell *shell, char c);
t_cmd	*ft_pop(t_cmd *lst, t_shell *shell);

////////////////////////////////UTILS.C/////////////////////////////////////////
int		is_token(char c);
int		count_args(t_cmd *tmp);
int		check_quotes(t_shell *shell);
int		check_specific_quotes(t_shell *shell, char c, char quotes);

/////////////////////////////EXEC_UTILS.C///////////////////////////////////////
void	exec_add_back(t_exec **exec, t_exec *new);
t_exec	*exec_create(char **args);
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Parsing////////////////////////////////////////////
//////////////////////////////Folder////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////DOLLARS.C////////////////////////////////////////
void	parse_dollars(t_shell *shell);
char	*extract_value(char *cmd, int i);

///////////////////////////////GET_CMD.C////////////////////////////////////////
t_cmd	*parse_rd(t_shell *shell);

///////////////////////////////PARSING.C////////////////////////////////////////
void	get_cmd(t_shell *shell);
void	parse_cmd(t_shell *shell);
void	parse_space(t_shell *shell);
void	parse_space_around(t_shell *shell);
void	parse_rd_token(t_shell *shell, int *j);

/////////////////////////////PIPE.C/////////////////////////////////////////////
void	set_pipe(t_shell *shell);

///////////////////////////////QUOTES.C/////////////////////////////////////////
void	remove_quotes(t_shell *shell);
char	*remove_quotes_utils(t_shell *shell, t_cmd *tmp, char c);

/////////////////////////////REDIRECTION.C//////////////////////////////////////
void	set_redirection(t_shell *shell);

#endif
