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

typedef struct s_cmd
{
	char			*cmd;
	char			**cmd_args;
	int				*fd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_shell
{
	char			*read;
	t_cmd			*cmd;
}	t_shell;
//////////////////////////////MAIN.C////////////////////////////////////////////
void	execution(void);
void	parsing(t_shell *shell);
void	init_shell(t_shell *shell);
//////////////////////////////UTILS_LST.C///////////////////////////////////////
void	lst_show(t_cmd *lst);
int		lst_len(t_cmd *lst);
void	lst_add_front(t_cmd **lst, t_cmd*new);
void	lst_add_back(t_cmd **lst, t_cmd *new);
t_cmd	*lst_create(char *str);
//////////////////////////////UTILS_LST2.C//////////////////////////////////////
void	printf_list(t_cmd *lst);
void	free_lst(t_shell *shell);
t_cmd	*ft_pop(t_cmd *lst);

///////////////////////////////PARSING.C////////////////////////////////////////
int		is_token(char c);
void	parse_cmd(t_shell *shell);
void	parse_space(t_shell *shell);
t_cmd	*parse_rd(t_shell *shell);
#endif