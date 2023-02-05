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

t_cmd	*parse_cmd(t_shell *shell)
{
	char 	**cmd;
	int		i;

	cmd = ft_split(shell->read, ' ');
	i = 0;
	while (cmd[i])
	{
		lst_add_back(&shell->cmd, lst_create(cmd[i]));
		i++;
	}
	free(cmd);

	return (shell->cmd);
}

void	execution()
{
	printf("Execution non implemente\n");
}

void	parsing(t_shell *shell)
{
	if (shell->read)
		add_history(shell->read);
	shell->cmd = parse_cmd(shell);
	lst_show(shell->cmd);
	execution();
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
//	char *vt[] = {"ls", NULL, NULL};
//	char *rd;
	t_shell shell;

	(void)ac;
	(void)av;
	(void)env;

	init_shell(&shell);
	while (1)
	{
		shell.read = readline("Minishell >");
		if (shell.read)
			parsing(&shell);
		else
			break 	;
	}
	free(shell.read);
	return (0);
}
