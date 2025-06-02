# Minishell

## External functions allowed

### External functions allowed

| Function| Library| Prototype| Return| Description|
|---------|--------|----------|-------|------------|
| access| `#include <unistd.h>`| `int access(const char *pathname, int mode);`| 0 on success, -1 on error (errno set)| Checks file accessibility (mode: F_OK, R_OK, W_OK, X_OK).|
| add_history| `#include <readline/history.h>`| `void add_history(const char *string);`| —| Adds string to the readline history list.|
| chdir| `#include <unistd.h>`| `int chdir(const char *path);`| 0 on success, -1 on error (errno set)| Changes the current working directory.|
| closedir| `#include <dirent.h>`| `int closedir(DIR *dirp);`| 0 on success, -1 on error (errno set)| Closes a directory stream.|
| close| `#include <unistd.h>`| `int close(int fd);`| 0 on success, -1 on error (errno set)| Closes a file descriptor.|
| dup| `#include <unistd.h>`| `int dup(int oldfd);`| New fd on success, −1 on error (errno set)| Duplicates a file descriptor.|
| dup2| `#include <unistd.h>`| `int dup2(int oldfd, int newfd);`| newfd on success, −1 on error (errno set)| Duplicates oldfd to newfd (closing newfd first if needed).|
| execve| `#include <unistd.h>`| `int execve(const char *pathname, char *const argv[], char *const envp[]);`| Does not return on success; −1 on error (errno set) | Executes the program pointed to by pathname with the given arguments and environment.|
| exit| `#include <stdlib.h>`| `void exit(int status);`| —| Terminates the process with the specified status.|
| fstat| `#include <sys/stat.h>`| `int fstat(int fd, struct stat *buf);`| 0 on success, -1 on error (errno set)| Retrieves file status for the open file descriptor fd.|
| fork| `#include <unistd.h>`| `pid_t fork(void);`| PID of child in parent, 0 in child, −1 on error| Creates a new process by duplicating the calling process.|
| free| `#include <stdlib.h>`| `void free(void *ptr);`| —| Deallocates memory previously allocated by malloc, calloc, or realloc.|
| getcwd| `#include <unistd.h>`| `char *getcwd(char *buf, size_t size);`| Pointer to buf on success, NULL on error (errno set)| Copies the absolute pathname of the current working directory into buf.|
| getenv| `#include <stdlib.h>`| `char *getenv(const char *name);`| Pointer to value or NULL if not found| Retrieves the value of the environment variable name.|
| ioctl| `#include <sys/ioctl.h>`| `int ioctl(int fd, unsigned long request, ...);`| 0 on success, −1 on error (errno set)| Performs device-specific control operations on file descriptor fd.|
| isatty| `#include <unistd.h>`| `int isatty(int fd);`| 1 if fd is a terminal, 0 otherwise| Tests whether fd refers to a terminal device.|
| kill| `#include <signal.h>`| `int kill(pid_t pid, int sig);`| 0 on success, −1 on error (errno set)| Sends the signal sig to the process or process group pid.|
| lstat| `#include <sys/stat.h>`| `int lstat(const char *pathname, struct stat *buf);`| 0 on success, -1 on error (errno set)| Like stat(), but returns information about a symbolic link itself.|
| malloc| `#include <stdlib.h>`| `void *malloc(size_t size);`| Pointer to allocated memory or NULL| Allocates size bytes of memory and returns a pointer to the allocated block.|
| open| `#include <fcntl.h>`| `int open(const char *pathname, int flags, mode_t mode);`| File descriptor on success, −1 on error (errno set) | Opens the file specified by pathname using flags and mode.|
| opendir| `#include <dirent.h>`| `DIR *opendir(const char *name);`| Pointer to DIR or NULL on error (errno set)| Opens a directory stream corresponding to the directory name.|
| perror| `#include <stdio.h>`| `void perror(const char *s);`| —| Prints s, a colon, a space, and the error message for the current errno.|
| pipe| `#include <unistd.h>`| `int pipe(int pipefd[2]);`| 0 on success, −1 on error (errno set)| Creates a pipe (pair of file descriptors for IPC).|
| printf| `#include <stdio.h>`| `int printf(const char *format, ...);`| Number of chars printed or negative on error| Writes formatted output to stdout.|
| readdir| `#include <dirent.h>`| `struct dirent *readdir(DIR *dirp);`| Pointer to dirent or NULL| Reads the next entry from the directory stream dirp.|
| read| `#include <unistd.h>`| `ssize_t read(int fd, void *buf, size_t count);`| Bytes read, 0 on EOF, −1 on error (errno set)| Attempts to read up to count bytes from file descriptor fd into buf.|
| readline| `#include <readline/readline.h>`| `char *readline(const char *prompt);`| malloc’ed string or NULL| Reads a line with prompt and line-editing; caller must free the returned string.|
| rl_clear_history| `#include <readline/history.h>`| `void rl_clear_history(void);`| —| Clears the entire readline history list.|
| rl_on_new_line  | `#include <readline/readline.h>`| `void rl_on_new_line(void);`| —| Informs readline that the cursor is on a new line (for redisplay).|
| rl_replace_line | `#include <readline/readline.h>`| `int rl_replace_line(const char *text, int clear_undo);`| 0 on success, non-zero on error| Replaces the contents of the editing buffer with text.|
| rl_redisplay| `#include <readline/readline.h>`| `int rl_redisplay(void);`| 0 on success, non-zero on error| Forces readline to redisplay the prompt and input line.|
| sigaction| `#include <signal.h>`| `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`| 0 on success, −1 on error (errno set)| Examines or changes the action taken on receipt of a specific signal.|
| sigaddset| `#include <signal.h>`| `int sigaddset(sigset_t *set, int signum);`| 0 on success, −1 on error (errno set)| Adds the specified signal to the signal set.|
| sigemptyset| `#include <signal.h>`| `int sigemptyset(sigset_t *set);`| 0 on success, −1 on error (errno set)| Initializes the signal set to exclude all signals.|
| signal| `#include <signal.h>`| `void (*signal(int signum, void (*handler)(int)))(int);`| Previous handler or SIG_ERR| Sets the handler for signal signum to handler.                                                          |
| stat| `#include <sys/stat.h>`| `int stat(const char *pathname, struct stat *buf);`| 0 on success, -1 on error (errno set)| Retrieves information about the file at pathname.|
| strerror| `#include <string.h>`| `char *strerror(int errnum);`| Pointer to message string| Returns the textual description of the error number errnum.|
| tcgetattr| `#include <termios.h>`| `int tcgetattr(int fd, struct termios *termios_p);`| 0 on success, -1 on error (errno set)| Gets the parameters associated with the terminal fd.|
| tcsetattr| `#include <termios.h>`| `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`| 0 on success, -1 on error (errno set)| Sets the parameters associated with the terminal fd.|
| tgetent| `#include <termcap.h>`| `int tgetent(char *bp, const char *name);`| 1 on success, 0 if not found, −1 on error| Loads the entry for terminal type name into buffer bp.|
| tgetflag| `#include <termcap.h>`| `int tgetflag(const char *id);`| 1 if true, 0 if false, −1 on error| Retrieves the boolean terminal capability id.|
| tgetnum| `#include <termcap.h>`| `int tgetnum(const char *id);`| Numeric value or −1 on error| Retrieves the numeric terminal capability id.|
| tgetstr| `#include <termcap.h>`| `char *tgetstr(const char *id, char **area);`| Pointer to string or NULL| Retrieves the string terminal capability id.|
| tgoto| `#include <termcap.h>`| `char *tgoto(const char *cap, int col, int row);`| Pointer to capability string| Encodes parameters col and row into the control string cap.|
| tputs| `#include <termcap.h>`| `int tputs(const char *str, int affcnt, int (*putc)(int));`| 0 on success, non-zero on error| Applies padding information and outputs str using putc.|
| ttyname| `#include <unistd.h>`| `char *ttyname(int fd);`| Pointer to terminal name or NULL| Returns the pathname of the terminal device associated with fd.|
| ttyslot| `#include <unistd.h>`| `int ttyslot(void);`| Terminal slot number or −1 on error| Returns the index of the terminal in the user accounting database (utmp).|
| unlink| `#include <unistd.h>`| `int unlink(const char *pathname);`| 0 on success, -1 on error (errno set)| Removes a link to a file from the filesystem.|
| wait| `#include <sys/wait.h>`| `pid_t wait(int *status);`| PID of terminated child or −1 on error (errno set)  | Suspends execution until any child process terminates.|
| wait3| `#include <sys/wait.h>`| `pid_t wait3(int *status, int options, struct rusage *rusage);`| PID of child or −1 on error (errno set)| Waits for any child and returns resource usage in rusage.|
| wait4| `#include <sys/wait.h>`| `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);`| PID of child or −1 on error (errno set)| Waits for a specific child process and returns resource usage.|
| waitpid| `#include <sys/wait.h>`| `pid_t waitpid(pid_t pid, int *status, int options);`| PID, 0 if no child matched, or −1 on error (errno)  | Waits for state changes in the specified child process.|
| write| `#include <unistd.h>`| `ssize_t write(int fd, const void *buf, size_t count);`| Bytes written, -1 on error (errno set)| Writes up to count bytes from buf to the file descriptor fd.|

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