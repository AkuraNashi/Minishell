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

int	count_args(t_shell *shell)
{
	int		count;
	t_cmd	*tmp;

	tmp = shell->cmd;
	count = 0;
	while(tmp)
	{
		if (tmp->cmd[0] != ' ' && is_token(tmp->cmd[0]))
			break	;
		if (tmp->next->cmd[0] == ' ')
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	get_cmd(t_shell *shell)
{
	char	**args;
	t_cmd	*tmp;
	int 	i;

	args = malloc(sizeof(char *) * count_args(shell));
	if (!args)
		printf("Erreur malloc, implementation error malloc requise...\n");
	tmp = shell->cmd;
	i = 0;
	while (tmp)
	{
		if (tmp->cmd[0] != ' ' && is_token(tmp->cmd[0]))
			break	;
		if (tmp->cmd[0] != ' ')
			args[i] = ft_strdup(tmp->cmd);
		i++;
		tmp = tmp->next;
	}
	i = 0;
	while (args[i])
	{
		printf("args : [%s]\n", args[i]);
		i++;
	}
}

void	parse_cmd(t_shell *shell)
{
	parse_space(shell);
//	get_cmd(shell);
}

void	parse_space(t_shell *shell)
{
	t_cmd	*tmp;
	char	c;

	tmp = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '\'' || tmp->cmd[0] == '\"')
		{
			c = tmp->cmd[0];
			tmp = tmp->next;
			while (tmp && tmp->cmd[0] != c)
				tmp = tmp->next;
			if (tmp)
				tmp = tmp->next;
		}
		else if (tmp->cmd[0] == ' ' && tmp->next->cmd[0] == ' ')
			tmp = ft_pop(tmp);
		else
			tmp = tmp->next;
	}
}
