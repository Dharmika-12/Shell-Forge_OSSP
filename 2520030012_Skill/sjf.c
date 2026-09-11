#include<stdio.h>
int main(){
int n,i,j;
int bt[10],temp;
int wt=0,tat;

printf("Enter number of processes: ");
scanf("%d", &n);

printf("Enter burst time:\n");

for(i=0;i<n;i++){
	printf("P%d: ",i+1);
	scanf("%d",&bt[i]);
}
for(i=0;i<n;i++){

for(j=i+1;j<n;j++){
	if(bt[i] > bt[j]){
		temp=bt[i];
		bt[i]=bt[j];
		bt[j]=temp;
	}
}
}
printf("\nBT\tWT\tTAT\n");

for(i=0;i<n;i++){
tat=wt+bt[i];
printf("%d\t%d\t%d\n",bt[i],wt,tat);
wt=wt+bt[i];
}

return 0;
}
