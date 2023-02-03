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

void	lst_show(t_cmd *lst)
{
	while (lst)
	{
		ft_printf("Liste : [%s]\n", lst->cmd);
		lst = lst->next;
	}
}

void	lst_add_front(t_cmd **lst, t_cmd*new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	lst_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_cmd	*lst_create(char *str)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd));
	tmp->cmd = str;
	tmp->next = NULL;
	return (tmp);
}

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
