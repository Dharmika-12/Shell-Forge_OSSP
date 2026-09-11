#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	printf("Parent process started \n");
	printf("Current process id : %d \n",getpid());
	printf("Parent process id : %d \n",getppid());
	pid =fork();
	if(pid<0){
		printf("Process failed\n");
		exit(1);
	}
	else if(pid ==0){
		printf("Child process\n");
		printf("Current process id : %d \n",getpid());
		printf("Parent process id : %d \n",getppid());
		execl("/bin/ls","ls","-l",NULL);
		printf("execl() sc failed");
	}
	else{
		printf("Parent process waiting for child process to be executed \n");
		wait(NULL);
		printf("Parent process resumed \n");
		printf("Child process finished \n");
		exit(0);
	}
return 0;
}
