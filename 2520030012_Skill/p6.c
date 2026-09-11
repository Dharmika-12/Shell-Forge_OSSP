#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid=fork();
	if(pid==0){
		printf("Child process id is: %d \n",getpid());
	}
	else{
		printf("Parent process id is: %d \n",getppid());
	}
	return 0;
}

