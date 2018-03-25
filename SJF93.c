#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int main()
{
	int a[MAX][7],i,count=0,totalt,small,n;
	float awt,atat;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	printf("\nEnter process name, arrival time and burst time: ");
	for(i=0;i<n;i++)
	{
		printf("\nProcess name: ");
		scanf("%d",&a[i][0]);
		printf("\nArrival time: ");
		scanf("%d",&a[i][1]);
		printf("\nBurst time: ");
		scanf("%d",&a[i][2]);
		count+=a[i][2];
		a[i][6]=-1;
	}
	count=count+a[0][1];
	totalt=a[0][1];
	while(totalt<count)
	{	
		for(i=0;i<n;i++)
		{
			if(a[i][6]==-1 && a[i][1]<=totalt)
			{
				small=i;
				break;
			}
		}	

		for(i=0;i<n;i++)
		{
					
			if(a[i][6]==-1 && a[i][1]<=totalt)
			{
				if(a[small][2]>a[i][2])
					small=i;
				/*else if(small==i)
					small=i;*/
			}
		}
		totalt=totalt+a[small][2];		//updation total time
		a[small][3]=totalt;			//ct of process
		a[small][6]=0;				//flag for process status
		//printf("\nTime %d",totalt);		
	}
	atat=0.0;
	awt=0.0;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\t");	
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i][0]);
		printf("\t %d",a[i][1]);
		printf("\t %d",a[i][2]);
		printf("\t %d",a[i][3]);
		a[i][4]=a[i][3]-a[i][1];		
		printf("\t %d",a[i][4]);
		a[i][5]=a[i][4]-a[i][2];
		printf("\t %d",a[i][5]);
		awt=awt+a[i][5];		
		atat=atat+a[i][4];	
	}
	atat=atat/n;
	awt=awt/n;
	printf("\nAverage TAT: %f",atat);
	printf("\nAverage WT: %f",awt);

return 0;
}
			
						
				
		
		
		

