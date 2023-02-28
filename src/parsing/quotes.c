/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:16 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:18 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes_utils(t_cmd *tmp, char *str, char c)
{
	int	j;
	int	i;

	i = 0;
	while (tmp->cmd[0] != c)
	{
		if (ft_strlen(tmp->cmd) == 1)
			str[i++] = tmp->cmd[0];
		else
		{
			j = 0;
			while (tmp->cmd[j])
				str[i++] = tmp->cmd[j++];
		}
		tmp = tmp->next;
	}
	str[i] = '\0';
}

void	remove_quotes(t_shell *shell)
{
	t_cmd	*tmp;
	char	*str;
	char	c;

	tmp = shell->cmd;
	while (tmp->next)
	{
		if (tmp->cmd[0] == '\"' || tmp->cmd[0] == '\'')
		{
			c = tmp->cmd[0];
			str = malloc(sizeof(char *) * (len_cmd(shell, c) + 1));
			if (tmp->prev != NULL)
				tmp = ft_pop(tmp);
			remove_quotes_utils(tmp, str, c);
			while (tmp->cmd[0] != c)
				tmp = ft_pop(tmp);
			free(tmp->cmd);
			tmp->cmd = str;
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}
