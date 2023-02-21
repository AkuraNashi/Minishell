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

int is_token(char c)
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

//"ls > cat.txt" == [ls][ ][>][ ][cat.txt]
t_cmd	*parse_rd(t_shell *shell)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (shell->read[i])
	{
		if (is_token(shell->read[i + 1]) || !shell->read[i + 1])
		{
			if (i - j + 1 > 0)
				lst_add_back(&shell->cmd, lst_create(ft_substr(shell->read, j, i - j + 1)));
			j = i;
			j++;
			if (shell->read[j])
				lst_add_back(&shell->cmd, lst_create(ft_substr(shell->read, j, 1)));
			j++;
		}
		i++;
	}
	return (shell->cmd);
}

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
	lst_show(shell->cmd);
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
