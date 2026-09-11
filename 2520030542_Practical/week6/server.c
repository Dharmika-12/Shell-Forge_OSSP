#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;
    char message[100];

    system("mkfifo client_fifo");
    system("mkfifo server_fifo");

    printf("Server waiting...\n");

    fd = open("client_fifo", O_RDONLY);

    read(fd, message, sizeof(message));

    printf("Client: %s\n", message);

    close(fd);

    fd = open("server_fifo", O_WRONLY);

    write(fd, "Hello Client", 13);

    close(fd);

    return 0;
}
