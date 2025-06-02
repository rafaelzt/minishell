/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:44:00 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/06/02 12:44:40 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

# define PROMPT "$> "

typedef int	(*builtin_fn)(char **args);

typedef struct s_builtin
{
	const char	*cmd; // cmd, e.g. "cd"
	builtin_fn	function; // pointer to command function
}	t_builtin;

typedef struct s_redir
{
	int		type; // IN, OUT, APPEND
	char	*file; // file 
}	t_redir;

typedef struct s_cmd
{
	char			**args; // string vector [command, arg1, ..., NULL]
	t_redir			*in; // input list redirection
	t_redir			*out; // output list redirection
	struct s_cmd	*next; // pipeline
}	t_cmd;

int	builtin_cd(char **args);
int	builtin_echo(char **args);
int	builtin_pwd(char **args);
int	builtin_export(char **args);
int	builtin_unset(char **args);
int	builtin_env(char **args);
int	builtin_exit(char **args);

#endif