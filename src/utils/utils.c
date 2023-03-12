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
	else if (c == '"')
		return (1);
	else if (c == '\'')
		return (1);
	else if (c == '\\')
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
int	count_args(t_cmd *tmp)
{
	int		count;

	count = 0;
	if (!is_token(tmp->cmd[0]))
		count = 1;
	while (tmp)
	{
		if (tmp->cmd[0] != ' ' && is_token(tmp->cmd[0]))
			break ;
		if (tmp->next && !is_token(tmp->next->cmd[0])
			&& !is_token(tmp->prev->cmd[0]))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_specific_quotes(t_shell *shell, char c, char quotes)
{
	int		count;
	t_cmd	*tmp;

	tmp = shell->cmd;
	count = 0;
	while (tmp)
	{
		if (tmp->cmd[0] == quotes)
		{
			tmp = tmp->next;
			while (tmp->next)
			{
				if (tmp->cmd[0] == quotes)
					break ;
				tmp = tmp->next;
			}
		}
		if (tmp->cmd[0] == c)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_quotes(t_shell *shell)
{
	if (check_specific_quotes(shell, '"', '\'') % 2 == 0
		&& check_specific_quotes(shell, '\'', '"') % 2 == 0)
		return (1);
	return (0);
}
