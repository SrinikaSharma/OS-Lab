#include<stdio.h>
int main(){
	int bt[20],wt[20],tat[20],i,j,temp;
	float avgwt = 0,avtat = 0;
	int n,pos,p[20];
	int total=0;
	printf("Enter the no.of processes: ");
	scanf("%d",&n);
	printf("\n Enter the burst time\n");
	for(i = 0;i < n;i++){
		printf("\nP[%d] = ",i+1);
		scanf("%d",&bt[i]);
		p[i] = i+1;
	}
	for(i = 0;i < n;i++){
		pos = i;
		for(j = i+1;j<n;j++){
			if(bt[j] < bt[pos]){
				pos = j;
			}
		}
		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}
	wt[0] = 0;
	for(i = 1;i < n;i++){
		wt[i] = 0;
		for(j = 0;j<i;j++)
			wt[i] += bt[j];
		total += wt[i];
	}
	avgwt = (float)total/n;
	total = 0;
	printf("Process \t Burst time\t Waiting time\t TAT\n");
	for(i = 0;i < n;i++){
		tat[i] = bt[i] + wt[i];
		total += tat[i];
		printf("P[%d]\t\t %d\t\t %d \t\t %d\n",p[i],bt[i],wt[i],tat[i]);
	}
	avtat = (float)total/n;
	printf("Avg wt: %f",avgwt);
	printf("\nAvg tat: %f",avtat);
}

/* Output
Enter the no.of processes: 4

 Enter the burst time

P[1] = 2

P[2] = 3

P[3] = 6

P[4] = 21
Process          Burst time      Waiting time    TAT
P[1]             2               0               2
P[2]             3               2               5
P[3]             6               5               11
P[4]             21              11              32
Avg wt: 4.500000
Avg tat: 12.500000
--------------------------------
*/
