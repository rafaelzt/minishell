/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:13:18 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/06/02 13:20:16 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html
int	main(int argc, char *argv[], char *envp[])
{
	// `char *input;` because readline allocate memory, because of that I use
	// free at the end of the wile block
	char	*input;
	int		status;
	char	*args[] = {"/home/rzamolo-/Documents/minishell", NULL};
	pid_t	pid;

	(void)argc;
	(void)argv;
	status = -1;
	pid = 0;
	while (1)
	{
		signal(SIGINT, SIG_IGN); // Ignore Ctrl+C
		input = readline(PROMPT); // read line from stdin
		// args = split_line(input); // Code split_line function (parse function)
		// status = execute_args(args); // Code execute_args (execute function)
		if (!input)
			break ;
		if (strcmp(input, "ls") == 0) // Have to import libft to use `ft_strcmp`
		{
				pid = fork();
				if (pid == 0)
				{
					execve("/usr/bin/ls", args, envp);
					perror("execve");
				}
				else
					perror("fork");
				// Can´t return... If I return from here the process ends and the loop closes
		}
		wait(NULL);
		if (*input != '\0')
			add_history(input);
		printf("%s\n", input);
		free(input);
		// free(args);
		if (status >= 0)
			exit(status); // Execute until status is greater than 1 or 0;
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