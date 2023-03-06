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
void	redirection(t_shell *shell, t_cmd *head)
{
	t_cmd	*tmp;
	t_cmd	*red;

	red = head;
	tmp = shell->cmd;
}

void	set_redirection(t_shell *shell)
{
	t_cmd 	*tmp;
	t_cmd	*head;

	tmp = shell->cmd;
	head = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '>')
			redirection(shell, head);
		else
		{

		}
		tmp = tmp->next;
	}
}