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

typedef struct s_redir
{
	int				infile;
	int				outfile;
	struct s_redir	*next;
	struct s_redir	*prev;
}	t_redir;

typedef struct s_exec
{
	char			**cmd_args;
	int				pipe[2];
	t_redir			*redir;
	struct s_exec	*next;
	struct s_exec	*prev;
}	t_exec;

typedef struct s_shell
{
	char			*read;
	t_cmd			*cmd;
}	t_shell;
//////////////////////////////MAIN.C////////////////////////////////////////////
void	execution(void);
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
void	lst_add_front(t_cmd **lst, t_cmd*new);
void	lst_add_back(t_cmd **lst, t_cmd *new);
t_cmd	*lst_create(char *str);

//////////////////////////////UTILS_LST2.C//////////////////////////////////////
void	printf_list(t_cmd *lst);
void	free_lst(t_shell *shell);
int		len_cmd(t_shell *shell, char c);
t_cmd	*ft_pop(t_cmd *lst, t_shell *shell);

////////////////////////////////UTILS_REDIR.C///////////////////////////////////
t_redir	*lst_create_redir(char *infile, char *outfile);
void	lst_add_back_redir(t_redir **lst, t_redir *new);
////////////////////////////////UTILS_EXEC.C////////////////////////////////////
t_exec	*lst_create_exec(char **str, t_redir *redir);
void	lst_add_back_exec(t_exec **lst, t_exec *new);

////////////////////////////////UTILS.C/////////////////////////////////////////
int		is_token(char c);
int		count_args(t_shell *shell);
int		check_quotes(t_shell *shell);
int		check_specific_quotes(t_shell *shell, char c);

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Parsing////////////////////////////////////////////
//////////////////////////////Folder////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////PARSING.C////////////////////////////////////////
t_cmd	*parse_rd(t_shell *shell);
void	get_cmd(t_shell *shell);
void	parse_cmd(t_shell *shell);
void	parse_space(t_shell *shell);

///////////////////////////////QUOTES.C/////////////////////////////////////////
void	remove_quotes(t_shell *shell);
char	*remove_quotes_utils(t_shell *shell, t_cmd *tmp, char c);

///////////////////////////////DOLLARS.C////////////////////////////////////////
void	parse_dollars(t_shell *shell);
char	*extract_value(char *cmd, int i);

/////////////////////////////REDIRECTION.C//////////////////////////////////////
void set_redirection(t_shell *shell);

#endif