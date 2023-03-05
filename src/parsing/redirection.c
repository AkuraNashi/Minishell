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

void set_redirection(t_shell *shell)
{
	t_cmd *tmp;

	tmp = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] != ' ' && tmp->cmd[0] != '|' && is_token(tmp->cmd[0]))
		{
			printf("redirection !\n");
		}
		tmp = tmp->next;
	}
}