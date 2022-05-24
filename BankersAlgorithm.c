#include<stdio.h>
int main()
{
	int n,r,p,i,j,available[10],allocate[10][10],max[10][10],need[10][10];
	printf("\nEnter the no of processes");
	scanf("%d",&n);
	printf("\nEnter the no of resources : ");
	scanf("%d",&r);
	printf("\nEnter the Max Need: ");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < r; j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter the allocation: ");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < r; j++)
		{
			scanf("%d",&allocate[i][j]);
		}
	}
	printf("\nEnter the available resources : ");
	for(int i = 0; i < r; i++)
		scanf("%d",&available[i]);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < r; j++)
		{
			need[i][j] = max[i][j] - allocate[i][j];
		}
	}
	int status[n];
	for(int i = 0; i < n; i++)
		status[i] = 0;
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for(int i = 0; i < n; i++)
		{
			int c = 0;
			for(int j = 0; j < r; j++)
			{
				if(status[i] == 0 && available[j] >= need[i][j])
				{
					c++;
					if(c == r)
					{
						for(int k = 0; k < r; k++)
							available[k] = available[k] + allocate[i][k];
						status[i] = 1;
						printf("P%d \t",i+1);
						flag = 1;
					}
				}
			}
		}
	}
	int c1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(status[i] == 1)
			c1++;
	}
		if(c1 == n)
			printf("\nProcesses are in safe state");
		else
			printf("\nProcesses enter deadlock");
}

/* Output

Enter the no of processes5
Enter the no of resources : 3
Enter the Max Need: 7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the allocation: 0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the available resources : 3 3 2
P2 	P4 	P5 	P1 	P3 	
Processes are in safe state

*/
