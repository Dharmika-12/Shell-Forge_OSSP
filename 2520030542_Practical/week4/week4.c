#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if(pid1 < 0)
    {
        printf("Process failed.\n");
        exit(1);
    }
    else if(pid1 == 0)
    {
        printf("Child 1: PID = %d\n", getpid());
        sleep(1);
        printf("Child 1 finished.\n");
        exit(0);
    }
    else
    {
        pid2 = fork();

        if(pid2 < 0)
        {
            printf("Process failed.\n");
            exit(1);
        }
        else if(pid2 == 0)
        {
            printf("Child 2: PID = %d\n", getpid());
            sleep(2);
            printf("Child 2 finished.\n");
            exit(0);
        }
        else
        {
            pid3 = fork();

            if(pid3 < 0)
            {
                printf("Process failed.\n");
                exit(1);
            }
            else if(pid3 == 0)
            {
                printf("Child 3: PID = %d\n", getpid());
                sleep(3);
                printf("Child 3 finished.\n");
                exit(0);
            }
            else
            {
                wait(NULL);
                printf("Parent: Child 1 completed using wait().\n");

                waitpid(pid2, NULL, 0);
                printf("Parent: Child 2 completed using waitpid().\n");

                waitpid(pid3, NULL, 0);
                printf("Parent: Child 3 completed using waitpid().\n");

                printf("All child processes completed.\n");
            }
        }
    }

    return 0;
}
