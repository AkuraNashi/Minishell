/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:56:42 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/12/22 22:56:43 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Affiche la linked list
/// \param lst Linked list a afficher
void	lst_show(t_cmd *lst)
{
	while (lst)
	{
		printf("Liste : [%s]\n", lst->cmd);
		lst = lst->next;
	}
}

/// Ajoute au debut de la linked list
/// \param lst Linked list qui va contenir le nouveau element
/// \param new Linked list a ajouter
void	lst_add_front(t_cmd **lst, t_cmd*new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/// Ajoute a la fin de la linked list
/// \param lst Linked list qui va contenir le nouveau element
/// \param new Linked list a ajouter
void	lst_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*current;
	t_cmd	*tmp_previous;

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
t_cmd	*lst_create(char *str)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return (NULL);
	tmp->cmd = str;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/// Calcul la length d'une linked list
/// \param lst La linked list a calculer
/// \return Taille de la linked list
int	lst_len(t_cmd *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
