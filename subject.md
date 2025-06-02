# Minishell

## External functions allowed

|Function|Library|Prototype|Return|Description|
|---|---|---|---|---|
|readline<br/>|#include <stdio.h><br/>#include <readline/readline.h><br/>#include <readline/history.h>|char *readline (const char *prompt);|**readline**  returns  the  text of the line read.  A blank line returns the empty string.  If EOF is encountered while reading a line, and the line is empty, NULL is returned.  If an EOF is read with a non-empty line, it is treated as a newline.|**readline**  will read a line from the terminal and return it, using prompt as a prompt.  If prompt is NULL or the empty string,no prompt is issued.  The line returned is allocated with malloc(3); the caller must free it when  finished. The  line  re‐turned has the final newline removed, so only the text of the line remains.<br/><br/>**readline**  offers editing capabilities while the user is entering the line. By default, the line editing commands are similar to those of emacs. A vi-style line editing interface is also available.<br/><br/>This manual page describes only the most basic use of readline.  Much more functionality is available; see The  GNU  Readline Library and The GNU History Library for additional information.|
|rl_clear_history<br/>|Lib|Proto|Return|Desc|
|rl_on_new_line<br/>|Lib|Proto|Return|Desc|
|rl_replace_line<br/>|Lib|Proto|Return|Desc|
|rl_redisplay<br/>|Lib|Proto|Return|Desc|
|add_history<br/>|#include <readline/history.h>|extern void add_history PARAMS((const char *));|Return|Desc|
|printf<br/>|Lib|Proto|Return|Desc|
|malloc<br/>|Lib|Proto|Return|Desc|
|free<br/>|Lib|Proto|Return|Desc|
|write<br/>|Lib|Proto|Return|Desc|
|access<br/>|Lib|Proto|Return|Desc|
|open<br/>|Lib|Proto|Return|Desc|
|read<br/>|Lib|Proto|Return|Desc|
|close<br/>|Lib|Proto|Return|Desc|
|fork<br/>|Lib|Proto|Return|Desc|
|wait<br/>|Lib|Proto|Return|Desc|
|waitpid<br/>|Lib|Proto|Return|Desc|
|wait3<br/>|Lib|Proto|Return|Desc|
|wait4<br/>|Lib|Proto|Return|Desc|
|signal<br/>|Lib|Proto|Return|Desc|
|sigaction<br/>|Lib|Proto|Return|Desc|
|sigemptyset<br/>|Lib|Proto|Return|Desc|
|sigaddset<br/>|Lib|Proto|Return|Desc|
|kill<br/>|Lib|Proto|Return|Desc|
|exit<br/>|Lib|Proto|Return|Desc|
|getcwd<br/>|#include <unistd.h>|char *getcwd(char buf[.size], size_t size);|On success, these functions return a pointer to a string containing the pathname of the current working directory.  In the case of getcwd() and getwd() this is the same value as buf.<br/><br/>
On failure, these functions return NULL, and errno is set to indicate the error.  The contents of the array pointed to by _buf_ are undefined on error.|Desc|
|chdir<br/>|Lib|Proto|Return|Desc|
|stat<br/>|Lib|Proto|Return|Desc|
|lstat<br/>|Lib|Proto|Return|Desc|
|fstat<br/>|Lib|Proto|Return|Desc|
|unlink<br/>|Lib|Proto|Return|Desc|
|execve<br/>|#include <unistd.h>| int execve(const char *pathname, char *const _Nullable argv[], char *const _Nullable envp[]);|On success, execve() does not return, on error -1 is returned, and errno is set to indicate the error.|Desc|
|dup<br/>|Lib|Proto|Return|Desc|
|dup2<br/>|Lib|Proto|Return|Desc|
|pipe<br/>|Lib|Proto|Return|Desc|
|opendir<br/>|Lib|Proto|Return|Desc|
|readdir<br/>|Lib|Proto|Return|Desc|
|closedir<br/>|Lib|Proto|Return|Desc|
|strerror<br/>|Lib|Proto|Return|Desc|
|perror<br/>|Lib|Proto|Return|Desc|
|isatty<br/>|Lib|Proto|Return|Desc|
|ttyname<br/>|Lib|Proto|Return|Desc|
|ttyslot<br/>|Lib|Proto|Return|Desc|
|ioctl<br/>|Lib|Proto|Return|Desc|
|getenv<br/>|Lib|Proto|Return|Desc|
|tcsetattr<br/>|Lib|Proto|Return|Desc|
|tcgetattr<br/>|Lib|Proto|Return|Desc|
|tgetent<br/>|Lib|Proto|Return|Desc|
|tgetflag<br/>|Lib|Proto|Return|Desc|
|tgetnum<br/>|Lib|Proto|Return|Desc|
|tgetstr<br/>|Lib|Proto|Return|Desc|
|tgoto<br/>|Lib|Proto|Return|Desc|
|tputs<br/>|Lib|Proto|Return|Desc|

## Main part

Your shell should:
- Display a **prompt** when waiting for a new command.

- Have a working **history**.

- Search and launch the right executable (based on the `PATH` variable or using a
relative or an absolute path).

- Avoid using more than **one global variable** to indicate a received signal. Consider the implications: this approach ensures that your signal handler will not access your main data structures.

> Be careful. This global variable cannot provide any other information or data access than the number of a received signal. Therefore, using "norm" type structures in the global scope is
forbidden.

- Not interpret unclosed quotes or special characters which are not required by the
subject such as \ (backslash) or ; (semicolon).

- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.

- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- Implement **redirections**:
	- < should redirect input.
	- \> should redirect output.
	- << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
	- \>> should redirect output in append mode.
- Implement **pipes** (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.

- Handle **environment variables** ($ followed by a sequence of characters) which
should expand to their values.
- Handle `$?` which should expand to the exit status of the most recently executed
foreground pipeline.
- Handle `Ctrl-C`, `Ctrl-D` and `Ctrl-\` which should behave like in bash.
- In interactive mode:
	- `Ctrl-C` displays a new prompt on a new line.
	- `Ctrl-D` exits the shell.
	- `Ctrl-\` does nothing.
- Your shell must implement the following **builtins**:
	- echo with option -n
	- cd with only a relative or absolute path
	- pwd with no options
	- export with no options
	- unset with no options
	- env with no options or arguments
	- exit with no options

The readline() function can cause memory leaks. You don’t have to fix them. But
that **doesn’t mean your own code, yes the code you wrote, can have memory
leaks**.

## Bonus part
Your program has to implement:
- `&& `and `||` with parenthesis for priorities.
- Wildcards `*` should work for the current working directory.