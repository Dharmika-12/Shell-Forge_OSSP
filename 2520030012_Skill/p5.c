#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	printf("Current process id is: %d \n",getpid());
	printf("Parent process id id: %d \n",getppid());
	return 0;
}

	

