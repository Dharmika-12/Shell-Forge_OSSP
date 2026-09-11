#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	fork();
		printf("Parent process id: %d \n",getpid());
	
}

