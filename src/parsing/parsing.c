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

#include "minishell.h"

void	parse_space_around(t_shell *shell)
{
	t_cmd	*tmp;

	tmp = shell->cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '>' || tmp->cmd[0] == '<' || tmp->cmd[0] == '|')
		{
			if (tmp->prev->cmd[0] == ' ')
			{
				tmp = tmp->prev;
				tmp = ft_pop(tmp, shell);
			}
			if (tmp->next->cmd[0] == ' ')
			{
				tmp = tmp->next;
				tmp = ft_pop(tmp, shell);
			}
		}
		if (tmp)
			tmp = tmp->next;
	}
}

/// Execute toutes les commandes a faire pour le parsing
/// \param shell Structure shell
void	parse_cmd(t_shell *shell)
{
	if (!check_quotes(shell))
	{
		printf("Nb de quotes pas bon\n");
		exit(0);
	}
	parse_space(shell);
	parse_space_around(shell);
	remove_quotes(shell);
	parse_dollars(shell);
//	set_redirection(shell);
//	set_pipe(shell);
//	get_cmd(shell);
}

/// Recuperer le Readline du shell et le mets dans une linked list.
/// Si un token est rencontré, on recupere ce qu'il y avait avant
/// et on fait une linked liste avec
/// \param shell Structure shell
/// \return Retourne une linked list
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

///WIP
/// Permet de creer une linked list contenant les commandes a executer
/// \param shell Structure shell
void	get_cmd(t_shell *shell)
{
	char	**args;
	t_cmd	*tmp;
	int		i;

	args = malloc(sizeof(char *) * (count_args(shell) + 1));
	if (!args)
		printf("Erreur malloc, implementation error malloc requise...\n");
	tmp = shell->cmd;
	i = 0;
	while (tmp)
	{
		if (tmp->cmd[0] != ' ' && is_token(tmp->cmd[0]))
			break ;
		if (tmp->cmd[0] != ' ')
			args[i++] = tmp->cmd;
		tmp = tmp->next;
	}
	args[i] = NULL;
}

/// Enleve tout les espaces inutiles, ne garde qu'un seul espace
/// afin de pouvoir parser les commandes futures
/// \param shell Structure shell
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
			tmp = ft_pop(tmp, shell);
		else
			tmp = tmp->next;
	}
}
