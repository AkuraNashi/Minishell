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

void	execution(void)
{
	printf("Execution non implemente\n");
}

void	parsing(t_shell *shell)
{
	if (shell->read)
		add_history(shell->read);
	shell->cmd = parse_rd(shell);
	parse_cmd(shell);
	execution();
	printf_list(shell->cmd);
	free_lst(shell);
	free(shell->read);
}

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
	add_history("aaaaa bb         c \"ee       '  aaa   '   d  \"   .    dd");
	while (1)
	{
		shell.read = readline("Minishell >");
		if (shell.read)
			parsing(&shell);
		else
			break ;
	}
	free(shell.read);
	return (0);
}
