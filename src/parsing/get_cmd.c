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

t_cmd	*return_args_tmp(char ***args, t_cmd *tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp->cmd && tmp->cmd[0] != '|' && tmp->cmd[0] != '>'
		&& tmp->cmd[0] != '<')
	{
		if (tmp->cmd[0] != ' ')
		{
			(*args)[i] = tmp->cmd;
			i++;
		}
		tmp = tmp->next;
	}
	(*args)[i] = NULL;
	return (tmp);
}

/// Permet de creer une linked list contenant les commandes a executer
/// \param shell Structure shell
void	get_cmd(t_shell *shell)
{
	char	**args;
	t_cmd	*tmp;

	tmp = shell->cmd;
	while (tmp)
	{
		if (count_args(tmp))
		{
			args = malloc(sizeof(char *) * (count_args(tmp) + 1));
			tmp = return_args_tmp(&args, tmp);
			exec_add_back(&shell->exec, exec_create(args));
		}
		if (tmp)
			tmp = tmp->next;
	}
}

/// Ajoute a la fin de la linked list
/// \param lst Linked list qui va contenir le nouveau element
/// \param new Linked list a ajouter
void	exec_add_back(t_exec **exec, t_exec *new)
{
	t_exec	*current;
	t_exec	*tmp_previous;

	if (*exec == NULL)
		*exec = new;
	else
	{
		tmp_previous = *exec;
		current = *exec;
		while (current->next)
		{
			tmp_previous = current;
			current = current->next;
		}
		current->next = new;
		current->prev = tmp_previous;
	}
}

/// Creer un element de la linked list
/// \param args commande et arguments
t_exec	*exec_create(char **args)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	exec->cmd_args = args;
	exec->next = NULL;
	exec->prev = NULL;
	return (exec);
}
