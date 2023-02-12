/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:16 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:18 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

t_cmd	*parse_rd(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (shell->read[i])
	{
		if (is_token(shell->read[i + 1]) || !shell->read[i + 1])
		{
			if (i - j + 1 > 0)
				lst_add_back(&shell->cmd, lst_create(ft_substr(
							shell->read, j, i - j + 1)));
			j = i;
			j++;
			if (shell->read[j])
				lst_add_back(&shell->cmd, lst_create(ft_substr(
							shell->read, j, 1)));
			j++;
		}
		i++;
	}
	return (shell->cmd);
}

void	parse_cmd(t_shell *shell)
{
	parse_quotes(shell);
}

void	parse_quotes(t_shell *shell)
{
	t_cmd	*tmp;
	t_cmd	*new_tmp;
	char	c;
	int		b;

	b = 0;
	tmp = shell->cmd;
	while (tmp)
	{
		//bug avec aaaaa bb         c "ee       '  aaa   '   d  "   .    dd
		//Resultat attendu : [aaaaa][bb][c]["][ee][ ][ ][ ][ ][ ][ ][ ]['][ ][ ][aaa][ ][ ][ ]['][ ][ ][ ][d][ ][ ]["][.][dd]
		if ((tmp->cmd[0] == '\'' || tmp->cmd[0] == '\"') && b == 0)
		{
			c = tmp->cmd[0];
			b = 1;
		}
		else if ((tmp->cmd[0] == '\'' || tmp->cmd[0] == '\"') && b == 1 && tmp->cmd[0] == c)
		{
			c = tmp->cmd[0];
			b = 0;
		}
		else if (tmp->cmd[0] == ' ' && b == 0 && c != tmp->cmd[0])
		{
			new_tmp->next = tmp->next;
			tmp->next = NULL;
			tmp = new_tmp;
		}
		else
			new_tmp = tmp;
		printf("b : [%d] char : [%s] c : [%c]\n", b, tmp->cmd, c);
		tmp = tmp->next;
	}
}
