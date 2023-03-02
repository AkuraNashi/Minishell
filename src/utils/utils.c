/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:56:42 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/12/22 22:56:43 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Check is le character est un token
/// \param c character a checker
/// \return 1 si c'est un token 0 si non
int	is_token(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '|')
		return (1);
	else if (c == '\'')
		return (1);
	else if (c == '"')
		return (1);
	else if (c == '>')
		return (1);
	else if (c == '<')
		return (1);
	return (0);
}

/// Compte les arguments afin de pouvoir creer la taille d'un **char
/// \param shell Structure shell
/// \return nb d'arguments
int	count_args(t_shell *shell)
{
	int		count;
	t_cmd	*tmp;

	tmp = shell->cmd;
	count = 1;
	while (tmp)
	{
		if (is_token(tmp->cmd[0]))
			break ;
		if (tmp->next && !is_token(tmp->next->cmd[0]))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_quotes(t_shell *shell)
{
	int		countd;
	int		countq;
	t_cmd	*tmp;

	countd = 0;
	countq = 0;
	tmp = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '\"')
			countd++;
		if (tmp->cmd[0] == '\'')
			countq++;
		tmp = tmp->next;
	}
	if (countd % 2 == 0 && countq % 2 == 0)
		return (1);
	else
		return (0);
}
