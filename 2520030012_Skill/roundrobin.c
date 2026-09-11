#include <stdio.h>
int main()
{
int n, i;
int bt[10], rem[10];
int tq, time = 0;
int done;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter burst time:\n");
for(i = 0; i < n; i++){
	printf("P%d: ", i + 1);
	scanf("%d", &bt[i]);
	rem[i] = bt[i];
}

printf("Enter time quantum: ");
scanf("%d", &tq);
printf("\nExecution:\n");
while(1){
done = 1;

for(i = 0; i < n; i++){
	if(rem[i] > 0){
		done = 0;
		printf("P%d ", i + 1);
	if(rem[i] > tq){
		time = time + tq;
		rem[i] = rem[i] - tq;
	}
	else{
		time = time + rem[i];
		rem[i] = 0;
	}
	}
}
if(done == 1)
break;
}
printf("\nTotal time = %d\n", time);
return 0;
}
