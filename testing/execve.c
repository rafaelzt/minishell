#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int		i = 0;
	char	*lst[] = {"user1", "Hello", "World", NULL};
	char	*lst2[] = {"env", "ls", "/home/rzamolo-/Documents/minishell/testing", NULL};
	char	*envp[] = {"USER=someuser", "PATH=/usr/bin/", "DEBUG=1", NULL};
	pid_t	pid;

	printf("Main program started\n");
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/echo", lst, envp); // argv passed to /bin/echo, but some programs, like `echo` ignore the index = 0;
		perror("Could not execve [echo #1]");
		return (-1);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}

	wait(NULL);
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/echo", &lst[0], envp);
		perror("Could not execve [echo #2]");
		return (-1);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	
	wait(NULL);
	pid = fork();
	if (pid == 0)
	{
		execve("/usr/bin/env", lst2, envp);
		perror("Could not execve [env]");
		return (-1);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	return (0);
}

// If the execve() work properly, the process is changed to /bin/echo and my main process doesn't exist anymore.
// to workaround that we use forks

// It's a good practice to end a child process with `exit()` or `return`

