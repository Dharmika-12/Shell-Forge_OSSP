#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());

        printf("Child is waiting...\n");
        sleep(5);

        printf("Child is running...\n");
        sleep(2);

        printf("Child terminated\n");
    }
    else
    {
        printf("Parent Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
        printf("Child PID : %d\n", pid);

        printf("Parent waiting for child...\n");
        wait(NULL);

        printf("Parent terminated\n");
    }

    return 0;
}
