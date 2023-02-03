/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:23:10 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/28 15:23:17 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lst(t_shell *shell)
{
	t_cmd	*lst;
	t_cmd	*lst_tmp;

	lst = shell->cmd;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->cmd);
		free(lst);
		lst = lst_tmp;
	}
	shell->cmd = NULL;
}
