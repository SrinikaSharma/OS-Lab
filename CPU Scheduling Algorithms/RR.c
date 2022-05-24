#include<stdio.h>
int main(){
	int n,i,j,max_bt,bt[10],wt[10],tat[10],ct[10],qt;
	float avgwt =0,avgtat=0,temp=0;
	printf("Enter total no. of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the burst time for process %d:",i);
		scanf("%d",&bt[i]);
		ct[i] = bt[i];
	}
	printf("Enter the quantum time:");
	scanf("%d",&qt);
	max_bt = bt[0];
	for(i=1;i<n;i++)
		if(max_bt < bt[i])
			max_bt = bt[i];
	for(j=0;j < (max_bt / qt) +1;j++)
		for(i=0;i<n;i++)
			if(bt[i] != 0)
				if(bt[i] <= qt){
					tat[i] = temp + bt[i];
					temp = temp + bt[i];
					bt[i] =0;
				}
				else{
					bt[i] = bt[i] - qt;
					temp = temp + qt;
				}
    printf("\n\tPROCESSOR \t BURST TIME \t WAITING TIME \t TURN AROUND TIME\n");
	for(i=0;i<n;i++){
		wt[i]= tat[i] - ct[i];
		avgtat += tat[i];
		avgwt += wt[i];
        printf("\t %d \t\t %d \t\t %d \t\t %d \n",i+1,ct[i],wt[i],tat[i]);
	}
    printf("\nAverage waiting time:%f",avgwt);
	printf("\nAverage Turn around time:%f",avgtat);
}

/* Output

Enter total no. of process:4
Enter the burst time for process 0:21
Enter the burst time for process 1:3
Enter the burst time for process 2:6
Enter the burst time for process 3:2
Enter the quantum time:5

        PROCESSOR        BURST TIME      WAITING TIME    TURN AROUND TIME
         1               21              11              32
         2               3               5               8
         3               6               15              21
         4               2               13              15

Average waiting time:44.000000
Average Turn around time:76.000000
--------------------------------

*/
