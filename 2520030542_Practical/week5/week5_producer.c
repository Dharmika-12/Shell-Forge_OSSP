#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
int fd[2];
pid_t pid;
char data[] = "Hello from Parent";
char buffer[100];
pipe(fd);
pid = fork();
if (pid == 0)
{
// Child - Consumer
close(fd[1]);
read(fd[0], buffer, sizeof(buffer));
printf("Consumer received: %s\n", buffer);
close(fd[0]);
exit(0);
}
// Parent - Producer
close(fd[0]);
write(fd[1], data, sizeof(data));
close(fd[1]);
waitpid(pid, NULL, 0);
printf("Producer sent data successfully.\n");
return 0;
}
