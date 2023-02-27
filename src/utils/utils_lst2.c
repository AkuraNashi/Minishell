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

#include "../minishell.h"

/// Free la linked list
/// \param shell Structure shell
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

/// Affiche les char * de la linked list
/// \param lst La linked list a afficher
void	printf_list(t_cmd *lst)
{
	ft_printf("[");
	while (lst)
	{
		ft_printf("%s", lst->cmd);
		lst = lst->next;
	}
	ft_printf("]\n");
}

/// Permet de retirer une node de la linked list
/// \param lst Linked list dont on va enlever la node
/// \return la nouvelle Linked list
t_cmd	*ft_pop(t_cmd *lst)
{
	t_cmd	*tmp;

	tmp = NULL;
	if (lst)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
		tmp = lst->next;
		free(lst->cmd);
		free(lst);
	}
	return (tmp);
}

/// Permet de calculer la longueur total d'une string jusqu'a retrouver
///le char c
/// \param shell Structure Shell
/// \param c le char c a retrouver
/// \return la longueur total des strings de la Linked list
int	len_cmd(t_shell *shell, char c)
{
	t_cmd	*tmp;
	int		i;
	int		b;

	i = 0;
	b = 0;
	tmp = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == c && b)
			break ;
		if (tmp->cmd[0] == c)
			b = 1;
		if (b)
			i += ft_strlen(tmp->cmd);
		tmp = tmp->next;
	}
	return (i);
}
