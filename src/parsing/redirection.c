/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:16 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:18 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//<<HEREDOC
//< ENTREE

//> Redirection
//>> APPEND
void	redirection(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_redir	*red;

	red = NULL;
	tmp = cmd;
//	red->outfile = tmp->prev->cmd;
//	red->infile = tmp->next->cmd;

}

void	set_redirection(t_shell *shell)
{
	t_cmd 	*tmp;

	tmp = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '>')
			redirection(tmp);
		else
		{

		}
		tmp = tmp->next;
	}
}