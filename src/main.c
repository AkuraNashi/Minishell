/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:16 by lcamilo-          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:18 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Ajoute dans l'historique la commande passé, rentre dans la fonction parsing
/// Fais l'execution et free les linked list
/// \param shell Structure shell
void	parsing(t_shell *shell)
{
	if (shell->read)
		add_history(shell->read);
	shell->cmd = parse_rd(shell);
	parse_cmd(shell);
	execution();
	lst_show(shell->cmd);
	free_lst(shell);
	free(shell->read);
}

/// Initialise les variables de la structure shell
/// \param shell Structure shell
void	init_shell(t_shell *shell)
{
	shell->cmd = NULL;
	shell->read = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)ac;
	(void)av;
	(void)env;
	init_shell(&shell);
	add_history("cat | cat | cat | ls");
	add_history("echo \"  salut  \"");
	while (1)
	{
		shell.read = readline("Minishell >");
		if (shell.read)
			parsing(&shell);+
	}
	free(shell.read);
	return (0);
}
