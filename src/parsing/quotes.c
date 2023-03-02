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

char	*remove_quotes_utils(t_shell *shell, t_cmd *tmp, char c)
{
	int		j;
	int		i;
	char	*str;

	str = malloc(sizeof(char *) * (len_cmd(shell, c) + 1));
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
	return (str);
}

void	replace_str(char **replace, char *str)
{
	free(*replace);
	*replace = str;
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
			if (tmp != shell->cmd)
				tmp = ft_pop(tmp, shell);
			else
				tmp = ft_pop(tmp, shell);
			str = remove_quotes_utils(shell, tmp, c);
			while (tmp->cmd[0] != c)
				tmp = ft_pop(tmp, shell);
			replace_str(&tmp->cmd, str);
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}
