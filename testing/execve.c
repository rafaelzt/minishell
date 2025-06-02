#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int		i = 0;
	char	*lst[] = {"user1", "Hello", "World", NULL};
	char	*lst2[] = {"env", "Hello", "World", NULL};
	char	*envp[] = {"USER=someuser", "PATH=/custom/path", "DEBUG=1", NULL};
	pid_t	pid;

	pid = fork();
	printf("Main program started [%d]\n", pid);
	if (pid == 0)
	{
		if (execve("/bin/echo", lst, envp) == -1) // argv passed to /bin/echo, but some programs, like `echo` ignore the index = 0;
			perror("Could not execve");
		execve("/bin/echo", &lst[0], envp); // this execution is ignored
	}
	wait(NULL);
	pid = fork();
	if (pid == 0)
	{
		if (execve("/usr/bin/env", lst, envp) == -1)
			perror("Could not execve");
	}
	wait(NULL);
	return (0);
}