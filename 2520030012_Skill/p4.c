#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
printf("Current process id id: %d \n",getpid());
return 0;
}
