#include<stdio.h>
int main(){
int n,i;
int bt[10];
int wt=0,tat;

printf("Enter number of processes: ");
scanf("%d",&n);
printf("Enter burst time: \n");
for(i=0;i<n;i++){
	printf("P%d: ",i+1);
	scanf("%d", &bt[i]);
}

printf("\nProcess\tBT\tWT\tTAT\n");
for(i=0;i<n;i++){
	tat=wt+bt[i];
	printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt,tat);
	wt=wt+bt[i];
}
return 0;
}

