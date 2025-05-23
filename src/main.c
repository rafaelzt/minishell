/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:13:18 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/05/23 13:52:40 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	// `char *input;` because readline allocate memory, because of that I use
	// free at the end of the wile block
	char	*input;
	(void)argc;
	(void)argv;
	while (1)
	{
		signal(SIGINT, SIG_IGN); // Ignore Ctrl+C
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input != '\0')
			add_history(input);
		printf("%s\n",input);
		free(input);
	}
	return (0);
}

/*
		// Tokenize input
		char *args[64];
		int i = 0;
		args[i] = strtok(input, " ");
		while (args[i] && i < 63)
			args[++i] = strtok(NULL, " ");
		args[i] = NULL;

		if (args[0]) {
			pid_t pid = fork();
			if (pid == 0) {
				// In child process
				execvp(args[0], args);
				perror("execvp");
				exit(EXIT_FAILURE);
			} else if (pid > 0) {
				// In parent process
				waitpid(pid, NULL, 0);
			} else {
				perror("fork");
			}
		}
*/