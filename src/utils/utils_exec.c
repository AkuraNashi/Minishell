/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:16 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:18 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Ajoute a la fin de la linked list
/// \param lst Linked list qui va contenir le nouveau element
/// \param new Linked list a ajouter
void	lst_add_back_exec(t_exec **lst, t_exec *new)
{
	t_exec	*current;
	t_exec	*tmp_previous;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp_previous = *lst;
		current = *lst;
		while (current->next)
		{
			tmp_previous = current;
			current = current->next;
		}
		current->next = new;
		current->prev = tmp_previous;
	}
}

/// Creer une Linked list
/// \param str Ce que va contenir la linked list
/// \return La linked list creer
t_exec	*lst_create_exec(char **str, t_redir *redir)
{
	t_exec	*tmp;

	tmp = malloc(sizeof(t_exec));
	if (!tmp)
		return (NULL);
	tmp->cmd_args = str;
	tmp->redir = redir;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}
