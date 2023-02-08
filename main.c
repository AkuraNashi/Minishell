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
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (shell->read[i])
	{
		if (is_token(shell->read[i]))
		{
			j++;
			if (is_token(shell->read[i + 1]))
				j++;

		}
		else
		{
			j = 0;
			if (is_token(shell->read[i + 1]) || !shell->read[i + 1])
			{
				lst_add_back(&shell->cmd, lst_create(ft_substr(shell->read, x, i + j)));
				x += i;
			}
			i++;
		}
	}
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
	shell->cmd = parse_rd(shell);
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
